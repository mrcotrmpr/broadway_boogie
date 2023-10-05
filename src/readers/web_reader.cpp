#include "readers/web_reader.hpp"
#include <iostream>
#include <cpr/cpr.h>

void WebReader::download(const std::string& url) {
	cpr::Response r = cpr::Get(cpr::Url{"http://www.httpbin.org/get"});
	std::cout << r.url << std::endl;
	std::cout << r.status_code << std::endl;
	std::cout << r.header["content-type"] << std::endl;
	std::cout << r.text << std::endl;
}
