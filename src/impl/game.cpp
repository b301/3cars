#include "game.hpp"

// Constructor:
Game::Game(int cars_count)
{
    this->initializeVariables(cars_count);
    this->initializeWindow();
}

// Destructor:
Game::~Game()
{
    delete this->window;
}

// Private:
void Game::initializeVariables(int cars_count)
{
    this->window = nullptr;

    if (!this->font.loadFromFile("assets/valorax.otf"))
    {
        std::cout << "Error loading font: valorax" << std::endl;
    }

    std::vector<sf::Keyboard::Key> movement_keys = {
        sf::Keyboard::S,
        sf::Keyboard::D,
        sf::Keyboard::F,
        sf::Keyboard::G,
        sf::Keyboard::H,
        sf::Keyboard::J,
        sf::Keyboard::K,
        sf::Keyboard::L,
    };

    std::vector<sf::Color> colors = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan,
        sf::Color(255, 0, 255), // Pink
        sf::Color(255, 165, 0), // Orange
    };

    this->cars_handler = new CarsHandler(cars_count, movement_keys, colors);

    text.setFont(this->font);
    text.setString("SCORE IS IMMACULATE");
    text.setFillColor(sf::Color::White);
}

void Game::initializeWindow()
{
    this->video_mode = sf::VideoMode(this->window_width, this->window_height);
    this->window = new sf::RenderWindow(this->video_mode, this->game_title, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

// Public:
const bool Game::isWindowOpen() const
{
    return this->window->isOpen();
}

void Game::pollEvent()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            switch (this->event.key.code)
            {
            case sf::Keyboard::Escape:
                this->window->close();
                break;
            default:
                this->cars_handler->move(this->event.key.code);
                break;
            }
        }
    }
}

void Game::checkCollisions()
{
    // if any car collides
    if (this->cars_handler->checkCollisons())
    {
        // std::cout << "Game over" << std::endl;
        this->cars_handler->reset();
    }

    this->text.setString("Score: " + std::to_string(this->cars_handler->getScore()));
}

void Game::update()
{
    this->checkCollisions();
    this->pollEvent();
}

void Game::render()
{
    this->window->clear();

    // Render items here
    this->cars_handler->render(this->window);
    this->window->draw(this->text);

    this->window->display();
}
