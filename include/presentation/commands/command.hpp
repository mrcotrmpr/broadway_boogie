#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <memory>

class Game;

class Command {
public:
    virtual void execute(std::shared_ptr<Game> game) = 0;
    virtual ~Command() = default;
};

#endif // COMMAND_HPP
