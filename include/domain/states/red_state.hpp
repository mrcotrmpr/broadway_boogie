#ifndef RED_STATE_HPP
#define RED_STATE_HPP

#include "node_state.hpp"

class RedState : public NodeState {
public:
    void handleInteraction(std::shared_ptr<Game> game) override;
};

#endif // RED_STATE_HPP
