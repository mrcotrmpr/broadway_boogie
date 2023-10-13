#ifndef NODE_STATE_HPP
#define NODE_STATE_HPP

#include <memory>

class Node;
class Artist;
class Game;

class NodeState {
public:
    virtual void handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) = 0;
    virtual ~NodeState() = default;
};

#endif // NODE_STATE_HPP
