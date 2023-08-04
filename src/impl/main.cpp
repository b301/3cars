#include <cstdlib>

#include "game.hpp"


int main() {
    // providing a seed for the random number generator
    srand(static_cast<unsigned>(time(NULL)));

    Game game;

    while (game.isWindowOpen()) {
        game.update();
        game.render();
    }

    return 0;
}