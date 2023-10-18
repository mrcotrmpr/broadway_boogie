#include "managers/collision_manager.hpp"
#include "presentation/game.hpp"
#include "domain/artist.hpp"
#include "iostream"

void CollisionManager::checkCollisionsNaive(std::shared_ptr<Game> game)
{
	for (const auto& artist : game->artists) {
		// Collision with edges of window -> turn around 180 degrees
		if (artist->x < 0 || artist->x > game->museum->numRows || artist->y < 0 || artist->y > game->museum->numCols) {
			artist->direction = (artist->direction + 2) % 4;
		}

		// Collision with other artists
		for (const auto& otherArtist : game->artists) {
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

void CollisionManager::checkCollisionsQuadtree(std::shared_ptr<Game> game)
{
	// Collision with other artist -> color red
	// Collision with edges of window -> turn around 180 degrees
	// Collision with calculated path -> color red IF game->pathCollision == true
	// Render quadtree visually IF game->renderQuadtree == true}
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
