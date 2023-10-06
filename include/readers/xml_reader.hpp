#ifndef XML_READER_HPP
#define XML_READER_HPP

#include "reader.hpp"

class XMLReader : public Reader {
public:
	std::string read(const std::string& input) override;
};

#endif // XML_READER_HPP
