#ifndef CSV_READER_HPP
#define CSV_READER_HPP

#include <string>
#include <vector>

class CSVReader {
public:
    std::vector<std::vector<std::string>> read(const std::string& filename);
};

#endif // CSV_READER_HPP
