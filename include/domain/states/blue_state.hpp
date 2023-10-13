#ifndef BLUE_STATE_HPP
#define BLUE_STATE_HPP

#include "node_state.hpp"

class BlueState : public NodeState {
public:
    void handleInteraction(std::shared_ptr<Game> game) override;
};

#endif // BLUE_STATE_HPP
