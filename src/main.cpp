#include <iostream>
#include <vector>
#include "readers/csv_reader.hpp"
#include "readers/xml_reader.hpp"
#include "readers/web_reader.hpp"
#include "parsers/csv_parser.hpp"
#include "parsers/xml_parser.hpp"
#include "domain/museum.hpp"

int main() {
    const std::string csv_filename = "C:\\Users\\marco\\source\\repos\\test\\data\\artists.csv";
    const std::string xml_filename = "C:\\Users\\marco\\source\\repos\\test\\data\\graph.xml";

    CSVReader csvReader;
    std::vector<std::vector<std::string>> csvData = csvReader.read(csv_filename);

    CSVParser csvParser;
    std::vector<std::shared_ptr<Artist>> artists = csvParser.parse(csvData);

    for (const auto& artist : artists) {
        std::cout << "Artist: X=" << artist->x << ", Y=" << artist->y
            << ", VX=" << artist->vx << ", VY=" << artist->vy << std::endl;
    }

    XMLReader xmlReader;
    std::string xmlContent = xmlReader.read(xml_filename);

    XMLParser xmlParser;
    std::shared_ptr<Museum> museum = xmlParser.parse(xmlContent);

    std::cout << "numRows: " << museum->numRows << std::endl;
    std::cout << "numCols: " << museum->numCols << std::endl;

    std::cout << "Node Types:" << std::endl;
    for (auto nodeType : museum->nodeTypes) {
        std::cout << "Tag: " << nodeType->tag << ", RGB: (" << nodeType->red << ", " << nodeType->green << ", " << nodeType->blue << "), Weight: " << nodeType->weight << std::endl;
    }

    std::cout << "Nodes and Edges:" << std::endl;
    for (auto node : museum->nodes) {
        std::cout << "Node Tag: " << node->tag << ", X: " << node->x << ", Y: " << node->y << std::endl;

        std::cout << "Edges:" << std::endl;
        for (auto edge : node->edges) {
            std::cout << "  Edge X: " << edge->x << ", Y: " << edge->y << std::endl;
        }
    }

    WebReader webReader;
    webReader.download("");

    return 0;
}
