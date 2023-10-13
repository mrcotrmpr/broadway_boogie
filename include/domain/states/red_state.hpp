#ifndef RED_STATE_HPP
#define RED_STATE_HPP

#include "node_state.hpp"

class RedState : public NodeState {
public:
    void handleInteraction(std::shared_ptr<Game> game, float nodeX, float nodeY, float artistX, float artistY) override;
};

#endif // RED_STATE_HPP
