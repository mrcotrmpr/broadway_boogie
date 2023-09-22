#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include "domain/museum.hpp"
#include "string"
#include "memory"

class XMLParser {
public:
    std::shared_ptr<Museum> parse(const std::string& xmlData);
};

#endif // XML_PARSER_HPP
