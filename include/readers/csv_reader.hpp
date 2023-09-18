#ifndef CSV_READER_HPP
#define CSV_READER_HPP

#include <fstream>
#include <string>
#include <vector>

class CsvReader {
public:
    CsvReader(const std::string& filename, char delimiter = ',');

    bool isOpen() const;
    bool readRow(std::vector<std::string>& row);

private:
    std::ifstream file;
    char delimiter;
};

#endif // CSV_READER_HPP
