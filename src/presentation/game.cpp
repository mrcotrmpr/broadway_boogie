#include "presentation/game.hpp"
#include <iostream>
#include "domain/museum.hpp"
#include "presentation/sdl_facade.hpp"

void Game::start()
{
    sdl = std::make_shared<SDLFacade>();
    if (sdl->init(shared_from_this()) && sdl->createWindow("Museum", 800, 800)) {
        bool quit = false;
        while (!quit) {
            sdl->render();
            quit = !sdl->handleEvents();
        }
    }
    sdl->cleanup();
}

std::shared_ptr<Node> Game::getNode(float x, float y, float scaleX, float scaleY) {
    for (const auto& node : museum->nodes) {
        float scaledNodeX = node->x * scaleX;
        float scaledNodeY = node->y * scaleY;

        if (x >= scaledNodeX && x <= scaledNodeX + 14 && y >= scaledNodeY && y <= scaledNodeY + 14) {
            return node;
        }
    }
    return nullptr;
}

std::shared_ptr<Artist> Game::getArtist(float x, float y, float scaleX, float scaleY) {
    for (const auto& artist : artists) {
        float scaledNodeX = artist->x * scaleX;
        float scaledNodeY = artist->y * scaleY;

        if (x >= scaledNodeX && x <= scaledNodeX + 14 && y >= scaledNodeY && y <= scaledNodeY + 14) {
            return artist;
        }
    }
    return nullptr;
}

void Game::removeArtist(std::shared_ptr<Artist> artist) {
    auto it = std::find(artists.begin(), artists.end(), artist);
    if (it != artists.end()) {
        artists.erase(it);
    }
    else {
        std::cout << "Artist not found." << std::endl;
    }
}

std::shared_ptr<GameStateMemento> Game::createMemento()
{
    auto memento = std::make_shared<GameStateMemento>();
    memento->savedMuseum = this->museum;
    memento->savedArtists = this->artists;
    return memento;
}

void Game::restoreMemento(std::shared_ptr<GameStateMemento> memento)
{
    this->museum = memento->savedMuseum;
    this->artists = memento->savedArtists;
}
