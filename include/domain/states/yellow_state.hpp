#ifndef YELLOW_STATE_HPP
#define YELLOW_STATE_HPP

#include "node_state.hpp"

class YellowState : public NodeState {
public:
    void handleInteraction(std::shared_ptr<Game> game) override;
};

#endif // YELLOW_STATE_HPP
