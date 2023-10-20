#include <gtest/gtest.h>
#include "readers/xml_reader.hpp"

TEST(XMLReaderTest, TestRead) {
    auto xmlReader = std::make_shared<XMLReader>();
    const std::string xml_filename = "C:\\Users\\marco\\source\\repos\\test\\tests\\data\\graph.xml";
    std::string xml_data = xmlReader->read(xml_filename);

    ASSERT_FALSE(xml_data.empty());
    ASSERT_EQ(xml_data, "<?xml version=\"1.0\" ?>\n<canvas rows=\"2\" cols=\"2\">\n\t<nodeTypes>\n\t\t<nodeType tag=\"Y\" red=\"250\" green=\"201\" blue=\"1\" weight=\"1\"/>\n\t\t<nodeType tag=\"R\" red=\"221\" green=\"1\" blue=\"0\" weight=\"10\"/>\n\t</nodeTypes>\n\t<nodes>\n\t\t<Y x=\"0\" y=\"0\">\n\t\t\t<edges>\n\t\t\t\t<edge x=\"1\" y=\"0\"/>\n\t\t\t\t<edge x=\"0\" y=\"1\"/>\n\t\t\t</edges>\n\t\t</Y>\n\t\t<R x=\"1\" y=\"0\">\n\t\t\t<edges>\n\t\t\t\t<edge x=\"0\" y=\"0\"/>\n\t\t\t</edges>\n\t\t</R>\n\t</nodes>\n</canvas>\n");
}
