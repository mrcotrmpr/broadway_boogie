#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <vector>
#include <memory>
#include "string"
#include "domain/artist.hpp"
#include "factories/artist_factory.hpp"

class CSVParser {
public:
    std::vector<std::shared_ptr<Artist>> parse(const std::string& csvString);
};

#endif // CSV_PARSER_HPP
