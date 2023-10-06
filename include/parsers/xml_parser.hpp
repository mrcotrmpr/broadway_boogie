#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include <string>
#include <vector>
#include <memory>
#include "domain/museum.hpp"
#include "factories/museum_factory.hpp"

class XMLParser {
public:
    std::shared_ptr<Museum> parse(const std::string& xmlData);
    std::string trim(const std::string& str);
    std::shared_ptr<NodeType> parseNodeType(const std::string& line);
    std::shared_ptr<Node> parseNode(const std::string& line, char tag, std::vector<std::string> edgesStrings);
    std::vector<int> parseDimensions(const std::string& line);
};

#endif // XML_PARSER_HPP
