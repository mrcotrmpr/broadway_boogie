#ifndef GRAY_STATE_HPP
#define GRAY_STATE_HPP

#include "node_state.hpp"

class GrayState : public NodeState {
public:
    void handleInteraction(std::shared_ptr<Game> game, float nodeX, float nodeY, float artistX, float artistY) override;
};

#endif // GRAY_STATE_HPP
