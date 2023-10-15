#ifndef CARETAKER_HPP
#define CARETAKER_HPP

#include "game_state_memento.hpp"
#include <vector>
#include <memory>

class Caretaker {
public:
    Caretaker();
    void addMemento(std::shared_ptr<GameStateMemento> memento);
    std::shared_ptr<GameStateMemento> getMemento(int index);
    int getMementosCount() const;
private:
    std::vector<std::shared_ptr<GameStateMemento>> mementos;
};
#endif // CARETAKER_HPP
