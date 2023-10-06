#include <iostream>
#include <vector>
#include "readers/csv_reader.hpp"
#include "readers/xml_reader.hpp"
#include "readers/web_reader.hpp"
#include "parsers/csv_parser.hpp"
#include "parsers/xml_parser.hpp"
#include "domain/museum.hpp"

void printArtists(std::vector<std::shared_ptr<Artist>> artists) {
    for (const auto& artist : artists) {
        std::cout << "Artist: X=" << artist->x << ", Y=" << artist->y
            << ", VX=" << artist->vx << ", VY=" << artist->vy << std::endl;
    };
    std::cout << "---" << std::endl;
}

void printMuseum(std::shared_ptr<Museum> museum) {
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
    std::cout << "---" << std::endl;
}

int main() {
    // Files
    const std::string csv_filename = "C:\\Users\\marco\\source\\repos\\test\\data\\artists.csv";
    const std::string xml_filename = "C:\\Users\\marco\\source\\repos\\test\\data\\graph.xml";

    // Urls
    const std::string xml_url = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/graph.xml?alt=media";
    const std::string csv_url = "https://filebin.net/8eynljvrm1cq98ci/artists.csv";
 
    // Init readers
    CSVReader csvReader;
    XMLReader xmlReader;
    WebReader webReader;

    // Init parsers
    CSVParser csvParser;
    XMLParser xmlParser;

    // Test CSV
    std::string csv_data = csvReader.read(csv_filename);
    std::vector<std::shared_ptr<Artist>> artists = csvParser.parse(csv_data);
    printArtists(artists);

    // Test XML
    std::string xml_content = xmlReader.read(xml_filename);
    std::shared_ptr<Museum> museum = xmlParser.parse(xml_content);
    printMuseum(museum);

    // Test Web 
    std::string web_csv_data = webReader.read(csv_url);
    std::vector<std::shared_ptr<Artist>> web_artists = csvParser.parse(web_csv_data);
    printArtists(web_artists);

    std::string web_xml_content = webReader.read(xml_url);
    std::shared_ptr<Museum> web_museum = xmlParser.parse(web_xml_content);
    printMuseum(web_museum);

    return 0;
}
