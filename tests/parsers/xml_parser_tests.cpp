#include <gtest/gtest.h>
#include "parsers/xml_parser.hpp"

TEST(XMLParserTest, TestParse) {
    auto xmlParser = std::make_shared<XMLParser>();
    const std::string xml_data = "<?xml version=\"1.0\" ?>\n<canvas rows=\"2\" cols=\"2\">\n\t<nodeTypes>\n\t\t<nodeType tag=\"Y\" red=\"250\" green=\"201\" blue=\"1\" weight=\"1\"/>\n\t\t<nodeType tag=\"R\" red=\"221\" green=\"1\" blue=\"0\" weight=\"10\"/>\n\t</nodeTypes>\n\t<nodes>\n\t\t<Y x=\"0\" y=\"0\">\n\t\t\t<edges>\n\t\t\t\t<edge x=\"1\" y=\"0\"/>\n\t\t\t\t<edge x=\"0\" y=\"1\"/>\n\t\t\t</edges>\n\t\t</Y>\n\t\t<R x=\"1\" y=\"0\">\n\t\t\t<edges>\n\t\t\t\t<edge x=\"0\" y=\"0\"/>\n\t\t\t</edges>\n\t\t</R>\n\t</nodes>\n</canvas>\n";
    std::shared_ptr<Museum> loadedMuseum = xmlParser->parse(xml_data);

    ASSERT_TRUE(loadedMuseum != nullptr);
    ASSERT_EQ(loadedMuseum->numRows, 2);
    ASSERT_EQ(loadedMuseum->numCols, 2);

    ASSERT_EQ(loadedMuseum->nodeTypes.size(), 2);
    EXPECT_EQ(loadedMuseum->nodeTypes[0]->tag, 'Y');
    EXPECT_EQ(loadedMuseum->nodeTypes[0]->red, 250);
    EXPECT_EQ(loadedMuseum->nodeTypes[1]->tag, 'R');
    EXPECT_EQ(loadedMuseum->nodeTypes[1]->red, 221);

    ASSERT_EQ(loadedMuseum->nodes.size(), 2);
    EXPECT_EQ(loadedMuseum->nodes[0]->tag, 'Y');
    EXPECT_EQ(loadedMuseum->nodes[0]->x, 0);
    EXPECT_EQ(loadedMuseum->nodes[0]->edges[0]->x, 1);
    EXPECT_EQ(loadedMuseum->nodes[0]->edges[0]->y, 0);
    EXPECT_EQ(loadedMuseum->nodes[0]->edges[1]->x, 0);
    EXPECT_EQ(loadedMuseum->nodes[0]->edges[1]->y, 1);

    EXPECT_EQ(loadedMuseum->nodes[1]->tag, 'R');
    EXPECT_EQ(loadedMuseum->nodes[1]->x, 1);
    EXPECT_EQ(loadedMuseum->nodes[1]->edges[0]->x, 0);
    EXPECT_EQ(loadedMuseum->nodes[1]->edges[0]->y, 0);
}

TEST(XMLParserTest, TestTrim) {
    XMLParser xmlParser;
    std::string test_string = "   example string with leading and trailing whitespaces    ";
    std::string trimmed_string = xmlParser.trim(test_string);

    ASSERT_EQ(trimmed_string, "example string with leading and trailing whitespaces");
}
