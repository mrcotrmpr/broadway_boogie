#include "readers/xml_reader.hpp"
#include <fstream>
#include <iostream>

std::string XMLReader::read(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open the XML file" << std::endl;
        return "";
    }

    std::string content = "";
    std::string line;

    while (std::getline(file, line)) {
        content += line + "\n";
    }

    file.close();
    return content;
}
