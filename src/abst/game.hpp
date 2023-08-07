#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "globals.hpp"
#include "cars_handler.hpp"

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

    CarsHandler *cars_handler;

    const std::string game_title = "3 Cars";

    void initializeVariables(int cars_count);
    void initializeWindow();

public:
    Game(int cars_count);
    ~Game();

    const bool isWindowOpen() const;

    void pollEvent();
    void checkCollisions();
    void update();
    void render();
};

#endif // GAME_HPP