#include <iostream>
#include <vector>
#include "factories/artist_factory.hpp"

int main() {
    const std::string filename = "C:\\Users\\marco\\source\\repos\\test\\data\\artists.csv";

    try {
        std::vector<std::shared_ptr<Artist>> artists = ArtistFactory::createArtistsFromCsv(filename);

        for (const auto& artist : artists) {
            std::cout << "Artist: (x=" << artist->getX() << ", y=" << artist->getY()
                << ", vx=" << artist->getVX() << ", vy=" << artist->getVY() << ")" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
