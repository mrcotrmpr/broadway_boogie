#ifndef CSV_READER_HPP
#define CSV_READER_HPP

#include <string>
#include <vector>

class CSVReader {
public:
    explicit CSVReader(const std::string& filename);

    std::vector<std::vector<std::string>> readCSV();

private:
    std::string filename;
};

#endif // CSV_READER_HPP
