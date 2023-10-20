#include <gtest/gtest.h>
#include <vector>
#include "managers/artist_manager.hpp"
#include "domain/states/red_state.hpp"
#include "domain/node.hpp"
#include "domain/node_type.hpp"

TEST(ArtistManagerTest, TestLoadArtists) {
    auto artistManager = std::make_shared<ArtistManager>();
    auto loadedArtists = artistManager->loadArtists();

    ASSERT_FALSE(loadedArtists.empty());
}

TEST(ArtistManagerTest, TestMoveArtistsRandomly) {
    auto artist0 = std::make_shared<Artist>(0, 0, 0, 0);
    artist0->direction = 0;

    auto artist1 = std::make_shared<Artist>(0, 0, 0, 0);
    artist0->direction = 1;

    auto artist2 = std::make_shared<Artist>(0, 0, 0, 0);
    artist0->direction = 2;

    auto artist3 = std::make_shared<Artist>(0, 0, 0, 0);
    artist0->direction = 3;

    std::vector<std::shared_ptr<Artist>> artists = {
        artist0,
        artist1,
        artist2,
        artist3
    };

    auto artistManager = std::make_shared<ArtistManager>();
    artistManager->moveArtistsRandomly(artists, true);

    ASSERT_EQ(artist0->x, -0.05f);
    ASSERT_EQ(artist0->y, 0);

    ASSERT_EQ(artist1->x, -0.05f);
    ASSERT_EQ(artist1->y, 0);

    ASSERT_EQ(artist2->x, -0.05f);
    ASSERT_EQ(artist2->y, 0);

    ASSERT_EQ(artist3->x, 0);
    ASSERT_EQ(artist3->y, 0.05f);
}

TEST(ArtistManagerTest, TestDetectCollisions) {
    auto game = std::make_shared<Game>();

    std::vector<std::shared_ptr<NodeType>> nodeTypes;
    std::vector<std::shared_ptr<Node>> nodes;
    auto museum = std::make_shared<Museum>(1, 1, nodeTypes, nodes);
    game->museum = museum;

    auto artist = std::make_shared<Artist>(1, 1, 0, 0);
    game->addArtist(artist);

    auto node = std::make_shared<Node>('R', 1, 1);
    node->state = std::make_shared<RedState>();
    game->museum->nodes.push_back(node);

    auto artistManager = std::make_shared<ArtistManager>();
    artistManager->detectCollisions(game, 1, 1, true);

    ASSERT_TRUE(artist->leftFirstNode);
}
