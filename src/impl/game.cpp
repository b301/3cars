#include "game.hpp"




// Constructor:
Game::Game() {
    this->initializeVariables();
    this->initializeWindow();
}

// Destructor:
Game::~Game() {
    delete this->window;
}

// Private:
void Game::initializeVariables() {
    this->window = nullptr;

    if (!this->font.loadFromFile("assets/valorax.otf")) {
        std::cout << "Failed to load valorax.otf font" << std::endl;
    }

    text.setFont(this->font);
    text.setString("SCORE IS IMMACULATE");
    text.setFillColor(sf::Color::White);
}

void Game::initializeWindow() {
    this->video_mode = sf::VideoMode(this->window_width, this->window_height);
    this->window = new sf::RenderWindow(this->video_mode, this->game_title, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

// Public:
const bool Game::isWindowOpen() const {
    return this->window->isOpen();
}

void Game::pollEvent() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
            switch (this->event.key.code) {
                case sf::Keyboard::Escape:
                    this->window->close();
                    break;
                case sf::Keyboard::F:
                    // std::cout << "F pressed" << std::endl;
                    this->left_car.move();
                    break;
                case sf::Keyboard::G:
                    // std::cout << "G pressed" << std::endl;
                    this->middle_car.move();
                    break;
                case sf::Keyboard::H:
                    // std::cout << "H pressed" << std::endl;
                    this->right_car.move();
                    break;
            }
        }
    }
}

void Game::checkCollisions() {
    // if any car collides
    if (this->left_car.checkCollison() || this->middle_car.checkCollison() || this->right_car.checkCollison()) {
        std::cout << "Game over" << std::endl;
        this->left_car.reset();
        this->middle_car.reset();
        this->right_car.reset();
    }

    this->text.setString("Score: " + std::to_string(this->left_car.getScore()));
}

void Game::update() {
    this->checkCollisions();
    this->pollEvent();
}

void Game::render() {
    this->window->clear();

    // Render items here
    this->left_car.render(this->window);
    this->middle_car.render(this->window);
    this->right_car.render(this->window);

    this->window->draw(this->text);

    this->window->display();
}

