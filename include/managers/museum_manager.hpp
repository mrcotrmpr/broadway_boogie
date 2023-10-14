#ifndef MUSEUM_MANAGER_HPP
#define MUSEUM_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include <SDL.h>
#include "domain/museum.hpp"
#include "readers/xml_reader.hpp"
#include "readers/web_reader.hpp"
#include "parsers/xml_parser.hpp"

class MuseumManager {
public:
    std::shared_ptr<Museum> loadMuseum();
    void renderMuseum(SDL_Renderer* renderer, std::shared_ptr<Museum> museum, float scaleX, float scaleY);
    XMLReader xmlReader;
    WebReader webReader;
    XMLParser xmlParser;
};

#endif // MUSEUM_MANAGER_HPP
