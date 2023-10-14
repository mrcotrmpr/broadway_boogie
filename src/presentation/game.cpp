#include "presentation/game.hpp"
#include <iostream>
#include "readers/csv_reader.hpp"
#include "readers/xml_reader.hpp"
#include "readers/web_reader.hpp"
#include "parsers/csv_parser.hpp"
#include "parsers/xml_parser.hpp"
#include "domain/museum.hpp"
#include "presentation/sdl_facade.hpp"

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

void Game::start() {
    while (true) {
        int choice;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            displayMenu();
            std::cin >> choice;
            processChoice(choice);
        }
    }
}

void Game::displayMenu() const {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Load artists (local)" << std::endl;
    std::cout << "2. Load museum (local)" << std::endl;
    std::cout << "3. Load artists (web)" << std::endl;
    std::cout << "4. Load museum (web)" << std::endl;
    std::cout << "5. Print artists" << std::endl;
    std::cout << "6. Print museum" << std::endl;
    std::cout << "7. Start animation" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void Game::processChoice(int choice) {
    std::string csv_data;
    std::string xml_content;

    switch (choice) {
    case 1:
        // Load Artists
        csv_data = csvReader.read(csv_filename);
        artists = csvParser.parse(csv_data);
        system("CLS");
        std::cout << "Artists loaded!" << std::endl;
        break;
    case 2:
        // Load Museum
        xml_content = xmlReader.read(xml_filename);
        museum = xmlParser.parse(xml_content);
        system("CLS");
        std::cout << "Museum loaded!" << std::endl;
        break;
    case 3:
        // Load Artists (web)
        std::cout << "Sending request to: " << csv_url << "..." << std::endl;
        csv_data = webReader.read(csv_url);
        artists = csvParser.parse(csv_data);
        system("CLS");
        std::cout << "Artists loaded!" << std::endl;
        break;
    case 4:
        // Load Museum (web)
        std::cout << "Sending request to: " << xml_url << "..." << std::endl;
        xml_content = webReader.read(xml_url);
        museum = xmlParser.parse(xml_content);
        system("CLS");
        std::cout << "Museum loaded!" << std::endl;
        break;
    case 5:
        // Print artists
        if (!artists.empty()) {
            printArtists();
        }
        else {
            system("CLS");
        }
        break;
    case 6:
        // Print museum
        if (museum) {
            printMuseum();
        }
        else {
            system("CLS");
        }
        break;
    case 7:
        if (artists.empty() || !museum) {
            system("CLS");
            std::cout << "Please load ";
            if (artists.empty()) std::cout << "artists";
            if (artists.empty() && !museum) std::cout << " and ";
            if (!museum) std::cout << "museum";
            std::cout << " data before starting the presentation." << std::endl;
        }
        else {
            // Start the presentation
            startPresentation();
            system("CLS");

            artists.clear();
            museum.reset();
        }
        break;
    case 8:
        // Exit the program
        std::cout << "Exiting the program." << std::endl;
        exit(0);
    default:
        system("CLS");
        std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        break;
    }
}

void Game::printArtists() const {
    system("CLS");
    for (const auto& artist : artists) {
        std::cout << "Artist: X=" << artist->x << ", Y=" << artist->y
            << ", VX=" << artist->vx << ", VY=" << artist->vy << std::endl;
    };
    std::cout << "---" << std::endl;
}

void Game::printMuseum() const {
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

void Game::startPresentation()
{
    sdl = std::make_shared<SDLFacade>();
    if (sdl->init(shared_from_this()) && sdl->createWindow("Museum", 800, 800)) {
        bool quit = false;
        while (!quit) {
            sdl->render();
            quit = !sdl->handleEvents();
        }
    }
    sdl->cleanup();
}

std::shared_ptr<Node> Game::getNode(float x, float y, float scaleX, float scaleY) {
    for (const auto& node : museum->nodes) {
        float scaledNodeX = node->x * scaleX;
        float scaledNodeY = node->y * scaleY;

        if (x >= scaledNodeX && x <= scaledNodeX + 14 && y >= scaledNodeY && y <= scaledNodeY + 14) {
            return node;
        }
    }
    return nullptr;
}

std::shared_ptr<Artist> Game::getArtist(float x, float y, float scaleX, float scaleY) {
    for (const auto& artist : artists) {
        float scaledNodeX = artist->x * scaleX;
        float scaledNodeY = artist->y * scaleY;

        if (x >= scaledNodeX && x <= scaledNodeX + 14 && y >= scaledNodeY && y <= scaledNodeY + 14) {
            return artist;
        }
    }
    return nullptr;
}

void Game::removeArtist(std::shared_ptr<Artist> artist) {
    auto it = std::find(artists.begin(), artists.end(), artist);
    if (it != artists.end()) {
        artists.erase(it);
    }
    else {
        std::cout << "Artist not found." << std::endl;
    }
}
