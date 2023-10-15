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

std::shared_ptr<GameStateMemento> Game::createMemento() {
    auto memento = std::make_shared<GameStateMemento>();

    if (museum) {
        memento->savedMuseum = std::make_shared<Museum>(*this->museum);
        memento->savedMuseum->nodes = std::vector<std::shared_ptr<Node>>();
        for (const auto& node : this->museum->nodes) {
            auto newNode = std::make_shared<Node>(*node);
            memento->savedMuseum->nodes.push_back(newNode);
        }
    }
    else {
        memento->savedMuseum = nullptr;
    }

    memento->savedArtists = std::vector<std::shared_ptr<Artist>>();
    for (const auto& artist : this->artists) {
        auto newArtist = std::make_shared<Artist>(*artist);
        memento->savedArtists.push_back(newArtist);
    }

    return memento;
}

void Game::restoreMemento(std::shared_ptr<GameStateMemento> memento)
{
    if (memento->savedMuseum) {
        this->museum = std::make_shared<Museum>(*memento->savedMuseum);
        this->museum->nodes.clear(); // Clear nodes vector before copying
        for (const auto& node : memento->savedMuseum->nodes) {
            auto newNode = std::make_shared<Node>(*node);
            this->museum->nodes.push_back(newNode);
        }
    }
    else {
        this->museum = nullptr;
    }

    this->artists.clear(); // Clear artists vector before copying
    for (const auto& artist : memento->savedArtists) {
        auto newArtist = std::make_shared<Artist>(*artist);
        this->artists.push_back(newArtist);
    }
}
