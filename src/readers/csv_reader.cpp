#include "readers/csv_reader.hpp"
#include <sstream>
#include <iostream>

CsvReader::CsvReader(const std::string& filename, char delimiter)
    : delimiter(delimiter) {
    file.open(filename);
}

bool CsvReader::isOpen() const {
    return file.is_open();
}

bool CsvReader::readRow(std::vector<std::string>& row) {
    row.clear();
    std::string line;
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, delimiter)) {
            row.push_back(cell);
        }
        return true;
    }
    return false;
}
