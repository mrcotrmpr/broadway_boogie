#ifndef NODE_STATE_HPP
#define NODE_STATE_HPP

#include <memory>
#include <string>

class Game;

class NodeState {
public:
    virtual void handleInteraction(std::shared_ptr<Game> game, float nodeX, float nodeY, float artistX, float artistY) = 0;
    virtual ~NodeState() = default;
};

#endif // NODE_STATE_HPP
