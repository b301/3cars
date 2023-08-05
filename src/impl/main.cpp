#include <cstdlib>

#include "game.hpp"


int main(int argc, char** argv) {
    // providing a seed for the random number generator
    srand(static_cast<unsigned>(time(NULL)));

    // get the first argument as the number of cars, if not provided, use the default value 3
    int cars_count = (argc > 1) ? atoi(argv[1]) : 3;
    

    Game* game = new Game(cars_count);

    while (game->isWindowOpen()) {
        game->update();
        game->render();
    }

    delete game;

    return 0;
}