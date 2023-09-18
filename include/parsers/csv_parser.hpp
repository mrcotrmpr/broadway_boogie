#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <vector>
#include <memory>
#include "string"
#include "domain/artist.hpp"
#include "factories/artist_factory.hpp"

class CSVParser {
public:
    CSVParser() = default;
    std::vector<std::shared_ptr<Artist>> parse(const std::vector<std::vector<std::string>>& csvData);
};

#endif // CSV_PARSER_HPP
