#include <iostream>
#include <vector>
#include "domain/artist.hpp"
#include "readers/csv_reader.hpp"
#include "factories/artist_factory.hpp"

int main() {
    const std::string filename = "C:\\Users\\marco\\source\\repos\\test\\data\\artists.csv";

    CSVReader csvReader(filename);
    std::vector<std::vector<std::string>> csvData;

    if (csvReader.readCSV(csvData)) {
        for (const auto& row : csvData) {
            if (row.size() == 4) {
                try {
                    float x = std::stof(row[0]);
                    float y = std::stof(row[1]);
                    float vx = std::stof(row[2]);
                    float vy = std::stof(row[3]);

                    std::shared_ptr<Artist> artist = ArtistFactory::createArtist(x, y, vx, vy);

                    std::cout << "Artist: X=" << artist->getX() << ", Y=" << artist->getY()
                        << ", VX=" << artist->getVX() << ", VY=" << artist->getVY() << std::endl;

                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << " in row starting with: " << row[0] << std::endl;
                    continue;
                }
            }
        }
    }
    else {
        std::cerr << "Failed to open or read the CSV file." << std::endl;
        return 1;
    }

    return 0;
}
