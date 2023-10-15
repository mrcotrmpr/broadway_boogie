#include "presentation/memento/caretaker.hpp"

Caretaker::Caretaker() {}

void Caretaker::addMemento(std::shared_ptr<GameStateMemento> memento) {
    mementos.push_back(memento);
}

std::shared_ptr<GameStateMemento> Caretaker::getMemento(int index) {
    if (!mementos.empty() && index >= 0 && index < mementos.size()) {
        return mementos[index];
    }
    return nullptr;
}

int Caretaker::getMementosCount() const {
    return mementos.size();
}
