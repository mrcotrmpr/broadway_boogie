#include "readers/csv_reader.hpp"
#include <fstream>

std::string CSVReader::read(const std::string& input) {
    std::ifstream file(input);
    if (!file.is_open()) {
        return "";
    }

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return fileContent;
}
