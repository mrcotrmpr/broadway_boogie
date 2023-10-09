#include "presentation/sdl_facade.hpp"
#include <iostream>
#include <unordered_map>
#include <cstdlib>

SDLFacade::SDLFacade() : window(nullptr), renderer(nullptr), initialized(false) {}

SDLFacade::~SDLFacade() {
    cleanup();
}

bool SDLFacade::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    initialized = true;
    return true;
}

bool SDLFacade::createWindow(const std::string& title, int width, int height) {
    if (!initialized) {
        std::cerr << "SDL not initialized. Call init() first." << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void SDLFacade::render(std::vector<std::shared_ptr<Artist>> artists, std::shared_ptr<Museum> museum) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int windowWidth = 800;
    int windowHeight = 800;
    float scaleX = static_cast<float>(windowWidth) / 53.0f;
    float scaleY = static_cast<float>(windowHeight) / 53.0f;

    renderMuseum(museum, scaleX, scaleY);
    renderArtists(artists, scaleX, scaleY);
    moveArtistsRandomly(artists);
    detectCollisions(artists, museum, scaleX, scaleY);

    SDL_RenderPresent(renderer);
}

void SDLFacade::renderMuseum(std::shared_ptr<Museum> museum, float scaleX, float scaleY) {
    std::unordered_map<char, std::shared_ptr<NodeType>> nodeTypeMap;
    for (auto type : museum->nodeTypes) {
        nodeTypeMap[type->tag] = type;
    }

    for (const auto& node : museum->nodes) {
        auto nodeTypeIt = nodeTypeMap.find(node->tag);

        if (nodeTypeIt != nodeTypeMap.end()) {
            SDL_SetRenderDrawColor(renderer, nodeTypeIt->second->red, nodeTypeIt->second->green, nodeTypeIt->second->blue, 255);
        }
        else {
            SDL_SetRenderDrawColor(renderer, 128, 0, 128, 255); // Default to purple if node type not found
        }

        // Calculate the screen coordinates of the node
        SDL_Rect nodeRect;
        nodeRect.x = static_cast<int>(node->x * scaleX);
        nodeRect.y = static_cast<int>(node->y * scaleY);
        nodeRect.w = 14;
        nodeRect.h = 14;
        SDL_RenderFillRect(renderer, &nodeRect);

        // Draw edges
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (const auto& edge : node->edges) {
            SDL_RenderDrawLine(renderer,
                static_cast<int>(node->x * scaleX),
                static_cast<int>(node->y * scaleY),
                static_cast<int>(edge->x * scaleX),
                static_cast<int>(edge->y * scaleY)
            );
        }
    }
}

void SDLFacade::renderArtists(std::vector<std::shared_ptr<Artist>>& artists, float scaleX, float scaleY) {
    // Render artists
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

void SDLFacade::moveArtistsRandomly(std::vector<std::shared_ptr<Artist>>& artists) {
    float deltaTime = 0.1f; // Adjust this to control the speed of movement
    float damping = 0.98f;  // Adjust this to control the smoothness of movement

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

void SDLFacade::detectCollisions(std::vector<std::shared_ptr<Artist>>& artists, std::shared_ptr<Museum> museum, float scaleX, float scaleY) {
    for (auto& artist : artists) {
        // Calculate the position of the artist on the scaled coordinates
        float artistX = artist->x * scaleX;
        float artistY = artist->y * scaleY;

        // Initialize variables to keep track of the previous node's coordinates
        static float prevNodeX = -1.0f;
        static float prevNodeY = -1.0f;

        // Initialize a flag to track if the artist is currently on a node
        bool artistOnNode = false;

        for (const auto& node : museum->nodes) {
            float nodeX = node->x * scaleX;
            float nodeY = node->y * scaleY;

            // Check if the artist's position is within the bounds of the node
            if (artistX >= nodeX && artistX <= nodeX + 14 && artistY >= nodeY && artistY <= nodeY + 14) {
                // Check if the artist is not already on a node
                if (!artistOnNode) {
                    // Check if the current node is different from the previous node
                    if (nodeX != prevNodeX || nodeY != prevNodeY) {
                        char nodeTag = getNodeTag(nodeX, nodeY, museum, scaleX, scaleY);
                        std::cout << "Artist passed over a node with color: ";

                        switch (nodeTag) {
                        case 'R':
                            std::cout << "red";
                            break;
                        case 'B':
                            std::cout << "blue";
                            break;
                        case 'Y':
                            std::cout << "yellow";
                            break;
                        case 'G':
                            std::cout << "gray";
                            break;
                        default:
                            std::cout << "unknown";
                            break;
                        }

                        std::cout << std::endl;

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

char SDLFacade::getNodeTag(float x, float y, std::shared_ptr<Museum> museum, float scaleX, float scaleY) {
    for (const auto& node : museum->nodes) {
        float scaledNodeX = node->x * scaleX;
        float scaledNodeY = node->y * scaleY;

        if (x >= scaledNodeX && x <= scaledNodeX + 14 && y >= scaledNodeY && y <= scaledNodeY + 14) {
            return node->tag;
        }
    }
    return 'W'; // Default to white if no node is found
}

bool SDLFacade::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
        else if (event.type == SDL_KEYDOWN) {
            handleKeyPress(event.key.keysym.sym);
        }
    }
    return true;
}

void SDLFacade::handleKeyPress(SDL_Keycode key) {
    switch (key) {
    case SDLK_SPACE:
        // Toggle the artistsMoving flag when the SPACE key is pressed
        artistsMoving = !artistsMoving;
        break;
    }
}

void SDLFacade::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    if (initialized) {
        SDL_Quit();
    }
}
