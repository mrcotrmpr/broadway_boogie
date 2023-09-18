#ifndef XML_READER_HPP
#define XML_READER_HPP

#include <string>

class XMLReader {
public:
    std::string read(const std::string& filename);
};

#endif // XML_READER_HPP
