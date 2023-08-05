#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <SFML/Window.hpp>

#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width
#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height

#define CAR_WIDTH 50.f
#define CAR_HEIGHT 80.f
#define CARS_DISTANCE_FROM_TOP WINDOW_HEIGHT * 0.6f

#define CAR_DEVIATION_FROM_MIDDLE 80.f

#define INITIAL_OBSTACLE_SPEED 6.f
#define OBSTACLE_TOP_SPEED_MULTIPLIER 2.f

#endif // GLOBALS_HPP