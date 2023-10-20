#include <gtest/gtest.h>
#include "managers/command_manager.hpp"
#include "presentation/commands/go_back_command.hpp"

TEST(CommandManagerTest, TestRegisterCommand) {
    auto commandManager = std::make_shared<CommandManager>();
    auto command = std::make_shared<GoBackCommand>();

    SDL_Keycode key = SDLK_t;
    commandManager->registerCommand(key, command);

    ASSERT_EQ(commandManager->commandMap[key], command);
}
