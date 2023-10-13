#ifndef RED_STATE_HPP
#define RED_STATE_HPP

#include "node_state.hpp"

class RedState : public NodeState {
public:
    void handleInteraction(std::shared_ptr<Game> game, std::shared_ptr<Node> node, std::shared_ptr<Artist> artist) override;
};

#endif // RED_STATE_HPP
