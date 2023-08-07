#ifndef CARS_HANDLER_HPP
#define CARS_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#include "globals.hpp"
#include "car.hpp"

class CarsHandler
{
private:
    std::vector<Car *> cars;

    // the length of movement_keys should be equal to cars_count
    void initializeCars(int cars_count, std::vector<sf::Keyboard::Key> movement_keys, std::vector<sf::Color> colors);

public:
    CarsHandler(int cars_count, std::vector<sf::Keyboard::Key> movement_keys, std::vector<sf::Color> colors);
    ~CarsHandler();

    void render(sf::RenderTarget *target);

    // movement get keyboard keypressed as parameter
    void move(sf::Keyboard::Key key);

    bool checkCollisons();
    void reset();

    int getScore();
};

#endif // CARS_HANDLER_HPP
