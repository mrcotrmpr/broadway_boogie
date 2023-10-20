#include <gtest/gtest.h>
#include "presentation/memento/game_state_memento.hpp"
#include "presentation/commands/go_back_command.hpp"
#include "presentation/sdl_facade.hpp"
#include "presentation/game.hpp"
#include <sstream>
#include <iostream>

TEST(GoBackCommandTest, TestGoBackCommand) {
    auto game = std::make_shared<Game>();
    auto sdlFacade = std::make_shared<SDLFacade>();
    game->sdl = sdlFacade;
    sdlFacade->init(game);

    for (int i = 0; i < 3; i++) {
        auto memento = std::make_shared<GameStateMemento>();
        game->sdl->mementoManager->addMemento(memento);
    }

    game->currentMementoIndex = 2;
    game->atPresent = true;

    auto goBackCommand = std::make_shared<GoBackCommand>();
    testing::internal::CaptureStdout();
    goBackCommand->execute(game);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "Current index: 1/2\n");
    ASSERT_FALSE(game->atPresent);
    ASSERT_EQ(game->currentMementoIndex, 1);
}
