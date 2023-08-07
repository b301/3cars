#ifndef FOOD_HPP
#define FOOD_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>

#include "globals.hpp"

class Food
{
private:
    float width, height, middle, deviation, speed, x, y, maximum_speed;
    int score = 0;
    bool scoreFlag;

    sf::CircleShape food;

    void initializeVariables(float width, float height, float middle, float deviation, float speed);
    void initializeFood();
    void randomizeLane();

public:
    Food(float width, float height, float middle, float deviation, float speed);
    ~Food();

    void render(sf::RenderTarget *target);
    void move(sf::RectangleShape &car);

    // get global bounds
    const sf::FloatRect getGlobalBounds() const;
    const int getScore();
    void resetScore();
    void setSpeed(float speed);
};

#endif // FOOD_HPP