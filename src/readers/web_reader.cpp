#include "readers/web_reader.hpp"
#include <iostream>
#include <cpr/cpr.h>

std::string WebReader::read(const std::string& input) {
	cpr::Response r = cpr::Get(cpr::Url{input});
	return r.text;
}
