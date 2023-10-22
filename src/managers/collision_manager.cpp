#include "managers/collision_manager.hpp"
#include "presentation/game.hpp"
#include "domain/artist.hpp"
#include "iostream"

void CollisionManager::checkCollisionsNaive(std::shared_ptr<Game> game)
{
	for (const auto& artist : game->getArtists()) {
		handleWindowCollisions(artist, game->museum->numRows, game->museum->numCols);
		handleArtistCollisions(artist, game->getArtists(), game->scaleX, game->scaleY);
		handlePathCollisions(artist, game);
	}
}

void CollisionManager::checkCollisionsQuadtree(std::shared_ptr<Game> game, SDL_Renderer* renderer)
{
	game->quadtree->root->update(game->getArtists());
	handleQuadtreeNodes(game->quadtree->root, renderer, game);
}

void CollisionManager::handleQuadtreeNodes(std::shared_ptr<QuadtreeNode> node, SDL_Renderer* renderer, std::shared_ptr<Game> game) {
	if (node) {

		// Render
		SDL_Rect rect = { static_cast<int>(node->x), static_cast<int>(node->y), static_cast<int>(node->width), static_cast<int>(node->height) };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &rect);

		// Check collision
		for (const auto& artist : node->getPoints()) {
			handleWindowCollisions(artist, game->museum->numRows, game->museum->numCols);
			handleArtistCollisions(artist, node->getPoints(), game->scaleX, game->scaleY);
			handlePathCollisions(artist, game);
		}

		for (const auto& child : node->children) {
			handleQuadtreeNodes(child, renderer, game);
		}
	}
}

void CollisionManager::handleWindowCollisions(std::shared_ptr<Artist> artist, int numRows, int numCols) {
	if (artist->x < 0 || artist->x > numRows || artist->y < 0 || artist->y > numCols) {
		artist->direction = (artist->direction + 2) % 4;
	}
}

void CollisionManager::handleArtistCollisions(std::shared_ptr<Artist> artist, const std::vector<std::shared_ptr<Artist>>& allArtists, float scaleX, float scaleY) {
	bool foundCollision = false;
	for (const auto& otherArtist : allArtists) {
		if (artist != otherArtist && artist->leftFirstNode && otherArtist->leftFirstNode) {
			if (checkCollision(artist, otherArtist, scaleX, scaleY)) {
				if (artist->lastCollision == nullptr || (artist->lastCollision == otherArtist && otherArtist->lastCollision == artist)) {
					artist->colorTag = 'R';
					artist->lastCollision = otherArtist;
					otherArtist->colorTag = 'R';
					otherArtist->lastCollision = artist;
					foundCollision = true;
					break;
				}
			}
		}
	}
	if (!foundCollision) {
		artist->colorTag = 'B';
		if (artist->lastCollision) {
			artist->lastCollision->colorTag = 'B';
			artist->lastCollision->lastCollision = nullptr;
		}
		artist->lastCollision = nullptr;
	}
}

bool CollisionManager::checkCollision(const std::shared_ptr<Artist>& artist1, const std::shared_ptr<Artist>& artist2, float scaleX, float scaleY) {
	int x1 = artist1->x * scaleX;
	int y1 = artist1->y * scaleY;
	int x2 = artist2->x * scaleX;
	int y2 = artist2->y * scaleY;

	int dimensions = 7; 

	if (x1 >= x2 &&
		x1 <= x2 + dimensions &&
		y1 >= y2 &&
		y1 <= y2 + dimensions) {
		return true;
	}

	return false;
}

void CollisionManager::handlePathCollisions(std::shared_ptr<Artist> artist, std::shared_ptr<Game> game) {
	if (game->pathCollision) {
		float artistX = artist->x * game->scaleX;
		float artistY = artist->y * game->scaleY;
		auto node = game->getNode(artistX, artistY, true);
		if (node != nullptr) {
			if (node->visited == 'P') {
				artist->colorTag = 'R';
			}
		}
	}
}
