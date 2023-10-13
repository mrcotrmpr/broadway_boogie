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
    float deltaTime = 0.1f; // Control the speed of movement
    float damping = 0.98f;  // Control the smoothness of movement

    for (auto& artist : artists) {
        if (artistsMoving) {
            // Apply damping to gradually slow down the artist's speed
            artist->vx *= damping;
            artist->vy *= damping;

            int direction = rand() % 2; // 0 for horizontal, 1 for vertical

            if (direction == 0) {
                artist->vx += (static_cast<float>(rand() % 3 - 1) * 0.1f);
            }
            else {
                artist->vy += (static_cast<float>(rand() % 3 - 1) * 0.1f);
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
                        std::shared_ptr<Node> node = getNode(nodeX, nodeY, game->museum, scaleX, scaleY);
                        node->state->handleInteraction(game);

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

std::shared_ptr<Node> ArtistManager::getNode(float x, float y, std::shared_ptr<Museum> museum, float scaleX, float scaleY) {
    for (const auto& node : museum->nodes) {
        float scaledNodeX = node->x * scaleX;
        float scaledNodeY = node->y * scaleY;

        if (x >= scaledNodeX && x <= scaledNodeX + 14 && y >= scaledNodeY && y <= scaledNodeY + 14) {
            return node;
        }
    }
    return nullptr;
}
