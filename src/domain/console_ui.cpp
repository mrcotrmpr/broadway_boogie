#include "domain/console_ui.hpp"
#include <iostream>
#include "readers/csv_reader.hpp"
#include "readers/xml_reader.hpp"
#include "readers/web_reader.hpp"
#include "parsers/csv_parser.hpp"
#include "parsers/xml_parser.hpp"
#include "domain/museum.hpp"

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

void ConsoleUI::start() {
    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;
        processChoice(choice);
    }
}

void ConsoleUI::displayMenu() const {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Print Artists (local)" << std::endl;
    std::cout << "2. Print Museum (local)" << std::endl;
    std::cout << "3. Print Museum (web)" << std::endl;
    std::cout << "4. Print Artists (web)" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void ConsoleUI::processChoice(int choice) {
    std::vector<std::shared_ptr<Artist>> artists;
    std::shared_ptr<Museum> museum;
    std::string csv_data;
    std::string xml_content;

    switch (choice) {
    case 1:
        // Print Artists
        csv_data = csvReader.read(csv_filename);
        artists = csvParser.parse(csv_data);
        printArtists(artists);
        break;
    case 2:
        // Print Museum
        xml_content = xmlReader.read(xml_filename);
        museum = xmlParser.parse(xml_content);
        printMuseum(museum);
        break;
    case 3:
        // Print Museum
        csv_data = webReader.read(csv_url);
        artists = csvParser.parse(csv_data);
        printArtists(artists);
        break;
    case 4:
        // Print Museum
        xml_content = webReader.read(xml_url);
        museum = xmlParser.parse(xml_content);
        printMuseum(museum);
        break;
    case 5:
        // Exit the program
        std::cout << "Exiting the program." << std::endl;
        exit(0);
    default:
        std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        break;
    }
}

void ConsoleUI::printArtists(std::vector<std::shared_ptr<Artist>> artists) const {
    system("CLS");
    for (const auto& artist : artists) {
        std::cout << "Artist: X=" << artist->x << ", Y=" << artist->y
            << ", VX=" << artist->vx << ", VY=" << artist->vy << std::endl;
    };
    std::cout << "---" << std::endl;
}

void ConsoleUI::printMuseum(std::shared_ptr<Museum> museum) const {
    system("CLS");
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
