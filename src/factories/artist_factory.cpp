#include "factories/artist_factory.hpp"
#include "readers/csv_reader.hpp"
#include "iostream"

std::vector<std::shared_ptr<Artist>> ArtistFactory::createArtistsFromCsv(const std::string& filename) {
    std::vector<std::shared_ptr<Artist>> artists;
    CsvReader csvReader(filename);

    if (!csvReader.isOpen()) {
        throw std::runtime_error("Error: Could not open the CSV file.");
    }

    std::vector<std::string> row;

    while (csvReader.readRow(row)) {
        try {
            if (row.size() == 4) {
                float x = std::stof(row[0]);
                float y = std::stof(row[1]);
                float vx = std::stof(row[2]);
                float vy = std::stof(row[3]);

                std::shared_ptr<Artist> artist = std::make_shared<Artist>(x, y, vx, vy);
                artists.push_back(artist);
            }
            else {
                throw std::runtime_error("Error: Invalid CSV row format.");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << " in row starting with: " << row[0] << std::endl;
            continue;
        }
    }

    return artists;
}
