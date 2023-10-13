#include "managers/artist_manager.hpp"

void ArtistManager::renderArtists(SDL_Renderer* renderer, std::vector<std::shared_ptr<Artist>>& artists, float scaleX, float scaleY) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (const auto& artist : artists) {
        SDL_Rect artistRect;
        artistRect.x = static_cast<int>(artist->x * scaleX);
        artistRect.y = static_cast<int>(artist->y * scaleY);
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

            // Initialize variables to keep track of the previous node's coordinates
            static float prevNodeX = -1.0f;
            static float prevNodeY = -1.0f;

            // Initialize a flag to track if the artist is currently on a node
            bool artistOnNode = false;

            for (const auto& node : game->museum->nodes) {
                float nodeX = node->x * scaleX;
                float nodeY = node->y * scaleY;

                // Check if the artist's position is within the bounds of the node
                if (artistX >= nodeX && artistX <= nodeX + 14 && artistY >= nodeY && artistY <= nodeY + 14) {
                    // Check if the artist is not already on a node
                    if (!artistOnNode) {
                        // Check if the current node is different from the previous node
                        if (nodeX != prevNodeX || nodeY != prevNodeY) {
                            std::shared_ptr<Node> node = game->getNode(nodeX, nodeY, scaleX, scaleY);
                            std::shared_ptr<Artist> artist = game->getArtist(artistX, artistY, scaleX, scaleY);

                            if (node != nullptr && artist != nullptr) {
                                node->state->handleInteraction(game, node, artist);
                            }

                            // Update the previous node's coordinates
                            prevNodeX = nodeX;
                            prevNodeY = nodeY;
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
