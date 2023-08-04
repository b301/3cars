#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>

#include "globals.hpp"


class Obstacle
{
    private:
        float width, height, middle, deviation, speed, x, y, maximum_speed;
        int score = 0;
        bool scoreFlag;

        sf::RectangleShape obstacle;

        void initializeVariables(float width, float height, float middle, float deviation, float speed);
        void initializeObstacle();
        void randomizeLane();
    public:
        Obstacle(float width, float height, float middle, float deviation, float speed);
        ~Obstacle();

        void render(sf::RenderTarget* target);
        void move();

        // get global bounds
        const sf::FloatRect getGlobalBounds() const;
        const getScore();
        void resetScore();
        void setSpeed(float speed);
};




#endif // OBSTACLE_HPP
