#include <gtest/gtest.h>
#include "presentation/commands/load_documents_command.hpp"
#include "presentation/game.hpp"
#include "managers/museum_manager.hpp"
#include "managers/artist_manager.hpp"

TEST(LoadDocumentsCommandTest, TestExecute) {
    auto game = std::make_shared<Game>();
    auto loadDocumentsCommand = std::make_shared<LoadDocumentsCommand>();

    loadDocumentsCommand->execute(game);

    ASSERT_TRUE(game->museum != nullptr);
    ASSERT_FALSE(game->getArtists().empty());
}
