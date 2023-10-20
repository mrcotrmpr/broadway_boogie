#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <SDL.h>
#include <memory>
#include <vector>
#include "domain/node.hpp"
#include "presentation/quadtree/quadtree_node.hpp"

class Game;
class Artist;

class CollisionManager {
public:
    void checkCollisionsNaive(std::shared_ptr<Game> game);
    void checkCollisionsQuadtree(std::shared_ptr<Game> game, SDL_Renderer* renderer);
    void handleQuadtreeNodes(std::shared_ptr<QuadtreeNode> node, SDL_Renderer* renderer, std::shared_ptr<Game> game);
    void handleWindowCollisions(std::shared_ptr<Artist> artist, int numRows, int numCols);
    void handleArtistCollisions(std::shared_ptr<Artist> artist, const std::vector<std::shared_ptr<Artist>>& allArtists, float scaleX, float scaleY);
    bool checkCollision(const std::shared_ptr<Artist>& artist1, const std::shared_ptr<Artist>& artist2, float scaleX, float scaleY);
    void handlePathCollisions(std::shared_ptr<Artist> artist, std::shared_ptr<Game> game);
};

#endif // COLLISION_MANAGER_HPP
