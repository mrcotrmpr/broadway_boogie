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
    bool checkCollision(const std::shared_ptr<Artist>& artist1, const std::shared_ptr<Artist>& artist2, float scaleX, float scaleY);
};

#endif // COLLISION_MANAGER_HPP
