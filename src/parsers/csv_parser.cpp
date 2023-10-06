#include "parsers/csv_parser.hpp"
#include <iostream>
#include <sstream>

std::vector<std::shared_ptr<Artist>> CSVParser::parse(const std::string& csvString) {
    std::vector<std::shared_ptr<Artist>> artists;
    std::istringstream dataStream(csvString);

    std::string line;
    while (std::getline(dataStream, line)) {
        std::istringstream lineStream(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

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
