#ifndef CAR_HPP
#define CAR_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "globals.hpp"
#include "obstacle.hpp"
#include "food.hpp"

class Car
{
private:
    sf::RectangleShape car;
    sf::Color color;
    float width, height, x, y, middle, deviation;
    sf::Keyboard::Key movement_key;
    Lane lane;

    Obstacle *obstacle;
    Food *food;

    void initializeVariables(float width, float height, float x, float y, float middle, float deviation, sf::Color color, sf::Keyboard::Key movement_key);
    void initializeCar(sf::Color color);
    void initializeEntities();

    Lane getLane();
    void setLane(Lane lane);

public:
    Car(float width, float height, float x, float y, float middle, float deviation, sf::Color color, sf::Keyboard::Key movement_key);
    ~Car();

    void render(sf::RenderTarget *target);

    // movement
    void move(sf::Keyboard::Key key);
    bool checkCollison();

    int getScore();
    void reset();
};

#endif // CAR_HPP
