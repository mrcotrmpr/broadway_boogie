#ifndef READER_HPP
#define READER_HPP

#include <string>

class Reader {
public:
	virtual std::string read(const std::string& input) = 0;
};

#endif // READER_HPP
