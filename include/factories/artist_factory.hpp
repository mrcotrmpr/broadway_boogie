#ifndef ARTIST_FACTORY_HPP
#define ARTIST_FACTORY_HPP

#include <memory>
#include <vector>
#include "string"
#include "domain/artist.hpp"

class ArtistFactory {
public:
    static std::vector<std::shared_ptr<Artist>> createArtistsFromCsv(const std::string& filename);

private:
    ArtistFactory(); // Private constructor to prevent instantiation.
};

#endif // ARTIST_FACTORY_HPP
