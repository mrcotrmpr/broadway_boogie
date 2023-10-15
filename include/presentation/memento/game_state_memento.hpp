#ifndef GAME_STATE_MEMENTO_HPP
#define GAME_STATE_MEMENTO_HPP

#include <memory>
#include <vector>
#include "domain/museum.hpp"
#include "domain/artist.hpp"

class GameStateMemento {
public:
    std::shared_ptr<Museum> savedMuseum;
    std::vector<std::shared_ptr<Artist>> savedArtists;
};

#endif // GAME_STATE_MEMENTO_HPP
