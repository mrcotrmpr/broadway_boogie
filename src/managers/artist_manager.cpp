#include "managers/artist_manager.hpp"

std::vector<std::shared_ptr<Artist>> ArtistManager::loadArtists()
{
    const std::string csv_filename = "C:\\Users\\marco\\source\\repos\\test\\data\\artists.csv";
    const std::string csv_url = "https://filebin.net/8eynljvrm1cq98ci/artists.csv";

    std::string csv_data = csvReader.read(csv_filename);
    return csvParser.parse(csv_data);
}

void ArtistManager::renderArtists(SDL_Renderer* renderer, std::vector<std::shared_ptr<Artist>>& artists, std::shared_ptr<Game> game) {
    for (const auto& artist : artists) {
        if (artist->colorTag == 'R') {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
        }
        else {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
        }

        SDL_Rect artistRect;
        artistRect.x = static_cast<int>(artist->x * game->scaleX);
        artistRect.y = static_cast<int>(artist->y * game->scaleY);
        artistRect.w = 7;
        artistRect.h = 7;
        SDL_RenderFillRect(renderer, &artistRect);
    }
}

void ArtistManager::moveArtistsRandomly(std::vector<std::shared_ptr<Artist>>& artists, bool artistsMoving) {
    float deltaTime = 0.5f; // Control the speed of movement
    float damping = 0.98f;  // Control the smoothness of movement

    for (auto& artist : artists) {
        if (artistsMoving) {
            // Apply damping to gradually slow down the artist's speed
            artist->vx *= damping;
            artist->vy *= damping;

            // Check the current direction of the artist
            if (artist->direction == 0) {
                artist->vy = -0.1f; // Move north
                artist->vx = 0.0f;
            }
            else if (artist->direction == 1) {
                artist->vx = 0.1f; // Move east
                artist->vy = 0.0f;
            }
            else if (artist->direction == 2) {
                artist->vy = 0.1f; // Move south
                artist->vx = 0.0f;
            }
            else if (artist->direction == 3) {
                artist->vx = -0.1f; // Move west
                artist->vy = 0.0f;
            }

            // Update position based on velocity
            artist->x += artist->vx * deltaTime;
            artist->y += artist->vy * deltaTime;
        }
    }
}

void ArtistManager::detectCollisions(std::shared_ptr<Game> game, float scaleX, float scaleY, bool artistsMoving) {
    if (!artistsMoving) {
        // If artists are not moving, don't perform collision detection
        return;
    }

    for (auto& artist : game->artists) {
        if (artist) {
            // Calculate the position of the artist on the scaled coordinates
            float artistX = artist->x * scaleX;
            float artistY = artist->y * scaleY;

            // Check if the artist is currently on a node
            bool artistOnNode = false;

            for (const auto& node : game->museum->nodes) {
                float nodeX = node->x * scaleX;
                float nodeY = node->y * scaleY;

                // Check if the artist's position is within the bounds of the node
                if (artistX >= nodeX && artistX <= nodeX + 14 && artistY >= nodeY && artistY <= nodeY + 14) {
                    // Check if the artist is not already on a node
                    if (!artistOnNode) {
                        // Check if the current node is different from the last node
                        if (node != artist->lastNode) {
                            node->state->handleInteraction(game, node, artist);

                            // Update the last node for the artist
                            auto it = std::find(game->artists.begin(), game->artists.end(), artist);
                            if (it != game->artists.end()) {
                                artist->lastNode = node;
                            }
                            artist->leftFirstNode = true;
                        }
                    }

                    // Set the flag to indicate that the artist is on a node
                    artistOnNode = true;
                }
                else {
                    // Artist is not on this node
                    artistOnNode = false;
                }
            }
        }
    }

    game->artists.insert(game->artists.end(), game->newArtists.begin(), game->newArtists.end());
    game->newArtists.clear(); // Clear the newArtists vector for the next iteration
}

