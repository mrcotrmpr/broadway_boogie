#include "parsers/csv_parser.hpp"
#include <iostream>

std::vector<std::shared_ptr<Artist>> CSVParser::parse(const std::vector<std::vector<std::string>>& csvData) {
    std::vector<std::shared_ptr<Artist>> artists;

    for (const auto& row : csvData) {
        if (row.size() == 4) {
            try {
                float x = std::stof(row[0]);
                float y = std::stof(row[1]);
                float vx = std::stof(row[2]);
                float vy = std::stof(row[3]);

                std::shared_ptr<Artist> artist = ArtistFactory::createArtist(x, y, vx, vy);
                artists.push_back(artist);

            }
            catch (const std::invalid_argument& e) {
                // Skip if row cannot be parsed to type float
                continue;
            }
        }
    }

    return artists;
}
