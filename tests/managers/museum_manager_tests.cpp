#include <gtest/gtest.h>
#include "managers/museum_manager.hpp"

TEST(MuseumManagerTest, TestLoadMuseum) {
    auto museumManager = std::make_shared<MuseumManager>();
    auto loadedMuseum = museumManager->loadMuseum();

    ASSERT_TRUE(loadedMuseum != nullptr);
}
