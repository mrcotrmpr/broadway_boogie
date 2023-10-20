#include "managers/collision_manager.hpp"
#include "presentation/game.hpp"
#include "domain/artist.hpp"
#include "iostream"

void CollisionManager::checkCollisionsNaive(std::shared_ptr<Game> game)
{
	for (const auto& artist : game->getArtists()) {
		// Collision with edges of window -> turn around 180 degrees
		if (artist->x < 0 || artist->x > game->museum->numRows || artist->y < 0 || artist->y > game->museum->numCols) {
			artist->direction = (artist->direction + 2) % 4;
		}

		// Collision with other artists
		for (const auto& otherArtist : game->getArtists()) {
			// Check if the two artists are distinct and are within the same position
			if (artist != otherArtist && artist->leftFirstNode && otherArtist->leftFirstNode) {
				if (checkCollision(artist, otherArtist, game->scaleX, game->scaleY)) {
					artist->colorTag = 'R';
					otherArtist->colorTag = 'R';
				}
			}
		}

		// Collision with calculated path
		if (game->pathCollision) {
			for (const auto& node : game->museum->nodes) {
				if (node->visited == 'P') {
					float artistX = artist->x * game->scaleX;
					float artistY = artist->y * game->scaleY;
					float nodeX = node->x * game->scaleX;
					float nodeY = node->y * game->scaleY;

					// Check if the artist's position collides with the node's position
					if (artistX >= nodeX && artistX <= nodeX + 14 && artistY >= nodeY && artistY <= nodeY + 14) {
						artist->colorTag = 'R';
					}
				}
			}
		}
	}
}

void CollisionManager::checkCollisionsQuadtree(std::shared_ptr<Game> game, SDL_Renderer* renderer)
{
	game->quadtree->root->update(game->getArtists());
	renderQuadtreeNodes(game->quadtree->root, renderer);
}

void CollisionManager::renderQuadtreeNodes(std::shared_ptr<QuadtreeNode> node, SDL_Renderer* renderer) {
	if (node) {

		// Rendering the current node as a box
		SDL_Rect rect = { static_cast<int>(node->x), static_cast<int>(node->y), static_cast<int>(node->width), static_cast<int>(node->height) };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &rect);

		// Rendering the children nodes
		for (const auto& child : node->children) {
			renderQuadtreeNodes(child, renderer);
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
