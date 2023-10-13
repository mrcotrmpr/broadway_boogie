#include "presentation/game.hpp"
#include <iostream>

int main() {
    std::shared_ptr<Game> app = std::make_shared<Game>();
    app->start();
    return 0;
}
