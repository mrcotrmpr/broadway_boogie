#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <SDL.h>
#include <memory>
#include <vector>
#include "domain/artist.hpp"
#include "domain/node.hpp"
#include "presentation/quadtree/quadtree_node.hpp"

class CollisionManager {
public:
    void checkCollisionsNaive(std::shared_ptr<Game> game);
    void checkCollisionsQuadtree(std::shared_ptr<Game> game, SDL_Renderer* renderer);
    void renderQuadtreeNodes(std::shared_ptr<QuadtreeNode> node, SDL_Renderer* renderer);
    bool checkCollision(const std::shared_ptr<Artist>& artist1, const std::shared_ptr<Artist>& artist2, float scaleX, float scaleY);
};

#endif // COLLISION_MANAGER_HPP
