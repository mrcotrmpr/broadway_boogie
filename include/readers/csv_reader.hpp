#ifndef CSV_READER_HPP
#define CSV_READER_HPP

#include "reader.hpp"

class CSVReader : public Reader {
public:
    std::string read(const std::string& input) override;
};

#endif // CSV_READER_HPP
