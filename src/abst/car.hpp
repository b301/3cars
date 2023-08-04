#ifndef CAR_HPP
#define CAR_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "globals.hpp"
#include "obstacle.hpp"


enum Lane { LEFT, RIGHT };

class Car
{
    private:
        sf::RectangleShape car;
        sf::Color color;
        float width, height, x, y, middle, deviation;
        Lane lane;

        Obstacle* obstacle;
 
        void initializeVariables(float width, float height, float x, float y, float middle, float deviation);
        void initializeCar(sf::Color color);
        void initializeObstacles();

        Lane getLane();
        void setLane(Lane lane);
    public:
        Car(float width, float height, float x, float y, float middle, float deviation, sf::Color color);
        ~Car();
        
        void render(sf::RenderTarget* target);

        // movement
        void move();
        bool checkCollison();
        int getScore();
        void reset();
};




#endif // CAR_HPP
