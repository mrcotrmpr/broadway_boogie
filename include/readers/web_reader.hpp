#ifndef WEB_READER_HPP
#define WEB_READER_HPP

#include "reader.hpp"

class WebReader : public Reader {
public:
    std::string read(const std::string& input) override;
};

#endif // WEB_READER_HPP
