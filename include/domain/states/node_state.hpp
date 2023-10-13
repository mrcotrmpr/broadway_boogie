#ifndef NODE_STATE_HPP
#define NODE_STATE_HPP

#include <memory>
#include <string>

class SDLFacade;

class NodeState {
public:
    virtual void handleInteraction(std::shared_ptr<SDLFacade> sdl) = 0;
    virtual ~NodeState() = default;
};

#endif // NODE_STATE_HPP
