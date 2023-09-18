#include <iostream>
#include <vector>
#include "readers/csv_reader.hpp"
#include "parsers/csv_parser.hpp"

int main() {
    const std::string filename = "C:\\Users\\marco\\source\\repos\\test\\data\\artists.csv";

    CSVReader csvReader(filename);
    std::vector<std::vector<std::string>> csvData = csvReader.readCSV();

    CSVParser csvParser;
    std::vector<std::shared_ptr<Artist>> artists = csvParser.parse(csvData);

    for (const auto& artist : artists) {
        std::cout << "Artist: X=" << artist->getX() << ", Y=" << artist->getY()
            << ", VX=" << artist->getVX() << ", VY=" << artist->getVY() << std::endl;
    }

    return 0;
}
