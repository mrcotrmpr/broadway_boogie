#include <gtest/gtest.h>
#include "presentation/game.hpp"
#include "domain/museum.hpp"
#include "domain/node.hpp"
#include "domain/artist.hpp"
#include "presentation/memento/game_state_memento.hpp"

TEST(GameTest, TestAddArtist) {
    auto game = std::make_shared<Game>();
    ASSERT_EQ(game->getArtists().size(), 0);

    auto artist = std::make_shared<Artist>(5, 10, 0, 0);
    game->addArtist(artist);

    ASSERT_EQ(game->getArtists().size(), 1);
}

TEST(GameTest, TestGetNode) {
    auto game = std::make_shared<Game>();
    game->museum = std::make_shared<Museum>();

    auto node = std::make_shared<Node>('A', 5, 5);
    game->museum->nodes.push_back(node);

    auto retrievedNode = game->getNode(5, 5, false);

    ASSERT_EQ(retrievedNode->tag, 'A');
    ASSERT_EQ(retrievedNode->x, 5);
    ASSERT_EQ(retrievedNode->y, 5);
}


TEST(GameTest, TestGetArtist) {
    auto game = std::make_shared<Game>();

    auto artist = std::make_shared<Artist>(1, 2, 3, 4);
    game->addArtist(artist);

    auto retrievedArtist = game->getArtist(1, 2, false);

    ASSERT_EQ(retrievedArtist->x, 1);
    ASSERT_EQ(retrievedArtist->y, 2);
    ASSERT_EQ(retrievedArtist->vx, 3);
    ASSERT_EQ(retrievedArtist->vy, 4);
}

TEST(GameTest, TestGetArtists) {
    auto game = std::make_shared<Game>();
    ASSERT_EQ(game->getArtists().size(), 0);

    for (int i = 0; i < 3; i++) {
        auto artist = std::make_shared<Artist>();
        game->addArtist(artist);
    }
    ASSERT_EQ(game->getArtists().size(), 3);
}

TEST(GameTest, TestGetArtistPtr) {
    auto game = std::make_shared<Game>();

    auto artist = std::make_shared<Artist>(10, 10, 0, 0);
    game->addArtist(artist);

    auto retrievedArtist = game->getArtist(artist);

    ASSERT_EQ(retrievedArtist->x, 10);
    ASSERT_EQ(retrievedArtist->y, 10);
}

TEST(GameTest, TestRemoveArtist) {
    auto game = std::make_shared<Game>();

    auto artist = std::make_shared<Artist>(10, 10, 0, 0);
    game->addArtist(artist);

    ASSERT_EQ(game->getArtists().size(), 1);

    game->removeArtist(artist);

    ASSERT_TRUE(game->getArtists().empty());
}

TEST(GameTest, TestCreateMemento) {
    auto game = std::make_shared<Game>();

    auto museum = std::make_shared<Museum>();
    game->museum = museum;

    auto node = std::make_shared<Node>();
    museum->nodes.push_back(node);

    auto artist = std::make_shared<Artist>();
    game->addArtist(artist);

    auto memento = game->createMemento();

    ASSERT_TRUE(memento != nullptr);
    ASSERT_TRUE(memento->savedMuseum != nullptr);
    ASSERT_EQ(memento->savedMuseum->nodes.size(), 1);
    ASSERT_EQ(memento->savedArtists.size(), 1);
}


TEST(GameTest, TestRestoreMemento) {
    auto game = std::make_shared<Game>();
    auto memento = std::make_shared<GameStateMemento>();

    auto museum = std::make_shared<Museum>();
    memento->savedMuseum = museum;

    auto node = std::make_shared<Node>();
    museum->nodes.push_back(node);

    auto artist = std::make_shared<Artist>();
    memento->savedArtists.push_back(artist);

    game->restoreMemento(memento);

    ASSERT_TRUE(game->museum != nullptr);
    ASSERT_EQ(game->museum->nodes.size(), 1);
    ASSERT_EQ(game->getArtists().size(), 1);
}
