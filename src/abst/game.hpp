#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "globals.hpp"
#include "car.hpp"


class Game
{
private:
    sf::RenderWindow *window;
    sf::VideoMode video_mode;
    sf::Event event;

    sf::Font font;
    sf::Text text;

    const float window_width = WINDOW_WIDTH;
    const float window_height = WINDOW_HEIGHT;

    // const float car_width = CAR_WIDTH;
    // const float car_height = CAR_HEIGHT;

    // define the left car object, should be at 200 px as x (middle of 400 px lane)
    Car left_car = Car(
        CAR_WIDTH, CAR_HEIGHT, 
        LANE_WIDTH / 2 - (CAR_WIDTH / 2) - CAR_DEVIATION_FROM_MIDDLE, 
        CARS_DISTANCE_FROM_TOP, 
        LANE_WIDTH / 2, 
        CAR_DEVIATION_FROM_MIDDLE,
        sf::Color::Red
    );
    Car middle_car = Car(
        CAR_WIDTH, CAR_HEIGHT, 
        LANE_WIDTH * 1.5 - (CAR_WIDTH / 2) - CAR_DEVIATION_FROM_MIDDLE, 
        CARS_DISTANCE_FROM_TOP,
        LANE_WIDTH * 1.5, 
        CAR_DEVIATION_FROM_MIDDLE,
        sf::Color::Green
    );
    Car right_car = Car(
        CAR_WIDTH, CAR_HEIGHT, 
        LANE_WIDTH * 2.5 - (CAR_WIDTH / 2) - CAR_DEVIATION_FROM_MIDDLE, 
        CARS_DISTANCE_FROM_TOP, 
        LANE_WIDTH * 2.5, 
        CAR_DEVIATION_FROM_MIDDLE,
        sf::Color::Blue
    );

    const std::string game_title = "3 Cars";

    void initializeVariables();
    void initializeWindow();

public:
    Game();
    ~Game();

    const bool isWindowOpen() const;

    void pollEvent();
    void checkCollisions();
    void update();
    void render();
};

#endif // GAME_HPP