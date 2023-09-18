#ifndef CSV_READER_HPP
#define CSV_READER_HPP

#include <string>
#include <vector>

class CSVReader {
public:
    explicit CSVReader(const std::string& filename);

    bool readCSV(std::vector<std::vector<std::string>>& data);

private:
    std::string filename;
};

#endif // CSV_READER_HPP
