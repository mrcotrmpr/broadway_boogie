#ifndef CSV_READER_HPP
#define CSV_READER_HPP

#include <string>
#include <vector>

class CSVReader {
public:
    CSVReader() = default;
    std::vector<std::vector<std::string>> readCSV(const std::string& filename);
};

#endif // CSV_READER_HPP
