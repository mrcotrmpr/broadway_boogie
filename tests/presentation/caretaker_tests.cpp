#include <gtest/gtest.h>
#include "presentation/memento/caretaker.hpp"

TEST(CaretakerTest, TestAddMemento) {
    auto caretaker = std::make_shared<Caretaker>();
    auto memento = std::make_shared<GameStateMemento>();

    caretaker->addMemento(memento);
    ASSERT_EQ(caretaker->getMementosCount(), 1);
}

TEST(CaretakerTest, TestGetMemento) {
    auto caretaker = std::make_shared<Caretaker>();
    auto memento = std::make_shared<GameStateMemento>();

    caretaker->addMemento(memento);
    ASSERT_EQ(caretaker->getMemento(0), memento);
}

TEST(CaretakerTest, TestGetMementosCount) {
    auto caretaker = std::make_shared<Caretaker>();
    auto memento1 = std::make_shared<GameStateMemento>();
    auto memento2 = std::make_shared<GameStateMemento>();

    caretaker->addMemento(memento1);
    caretaker->addMemento(memento2);
    ASSERT_EQ(caretaker->getMementosCount(), 2);
}
