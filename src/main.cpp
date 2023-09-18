#include <iostream>
#include <vector>
#include "readers/csv_reader.hpp"
#include "readers/xml_reader.hpp"
#include "parsers/csv_parser.hpp"

int main() {
    const std::string csv_filename = "C:\\Users\\marco\\source\\repos\\test\\data\\artists.csv";
    const std::string xml_filename = "C:\\Users\\marco\\source\\repos\\test\\data\\graph.xml";

    CSVReader csvReader;
    std::vector<std::vector<std::string>> csvData = csvReader.read(csv_filename);

    CSVParser csvParser;
    std::vector<std::shared_ptr<Artist>> artists = csvParser.parse(csvData);

    for (const auto& artist : artists) {
        std::cout << "Artist: X=" << artist->getX() << ", Y=" << artist->getY()
            << ", VX=" << artist->getVX() << ", VY=" << artist->getVY() << std::endl;
    }

    XMLReader xmlReader;
    std::string xmlContent = xmlReader.read(xml_filename);
    std::cout << xmlContent << std::endl;

    return 0;
}
