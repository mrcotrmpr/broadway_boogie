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
	renderQuadtreeNodes(game->quadtree->root, renderer);
}

void CollisionManager::renderQuadtreeNodes(std::shared_ptr<QuadtreeNode> node, SDL_Renderer* renderer) {
	if (node) {
		SDL_Rect rect = { static_cast<int>(node->x), static_cast<int>(node->y), static_cast<int>(node->width), static_cast<int>(node->height) };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &rect);

		for (const auto& child : node->children) {
			renderQuadtreeNodes(child, renderer);
		}
	}
}

void CollisionManager::handleWindowCollisions(std::shared_ptr<Artist> artist, int numRows, int numCols) {
	if (artist->x < 0 || artist->x > numRows || artist->y < 0 || artist->y > numCols) {
		artist->direction = (artist->direction + 2) % 4;
	}
}

void CollisionManager::handleArtistCollisions(std::shared_ptr<Artist> artist, const std::vector<std::shared_ptr<Artist>>& allArtists, float scaleX, float scaleY) {
	for (const auto& otherArtist : allArtists) {
		if (artist != otherArtist && artist->leftFirstNode && otherArtist->leftFirstNode) {
			if (checkCollision(artist, otherArtist, scaleX, scaleY)) {
				artist->colorTag = 'R';
				otherArtist->colorTag = 'R';
			}
		}
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
		for (const auto& node : game->museum->nodes) {
			if (node->visited == 'P') {
				float artistX = artist->x * game->scaleX;
				float artistY = artist->y * game->scaleY;
				float nodeX = node->x * game->scaleX;
				float nodeY = node->y * game->scaleY;

				if (artistX >= nodeX && artistX <= nodeX + 14 && artistY >= nodeY && artistY <= nodeY + 14) {
					artist->colorTag = 'R';
				}
			}
		}
	}
}
