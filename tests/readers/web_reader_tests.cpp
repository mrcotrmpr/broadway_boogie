#include <gtest/gtest.h>
#include "readers/web_reader.hpp"

TEST(WebReaderTest, TestRead) {
    auto webReader = std::make_shared<WebReader>();
    const std::string web_url = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/graph.xml?alt=media";
    std::string web_data = webReader->read(web_url);

    ASSERT_FALSE(web_data.empty());
    ASSERT_EQ(web_data.substr(0, 50), "<?xml version=\"1.0\" ?>\r\n<canvas rows=\"53\" cols=\"53");
}
