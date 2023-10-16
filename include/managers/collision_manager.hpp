#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <memory>
#include <vector>
#include "domain/artist.hpp"
#include "domain/node.hpp"

class CollisionManager {
public:
    void checkCollisionsNaive(std::shared_ptr<Game> game);
    void checkCollisionsQuadtree(std::shared_ptr<Game> game);
};

#endif // COLLISION_MANAGER_HPP
