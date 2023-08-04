#include "obstacle.hpp"


// Constructor
Obstacle::Obstacle(float width, float height, float middle, float deviation, float speed) {
    this->initializeVariables(width, height, middle, deviation, speed);
    this->initializeObstacle();
    this->randomizeLane();
}

// Destructor
Obstacle::~Obstacle() {
}

// Private
void Obstacle::initializeVariables(float width, float height, float middle, float deviation, float speed) {
    this->width = width;
    this->height = height;
    this->middle = middle;
    this->deviation = deviation;
    this->speed = speed;
    this->maximum_speed = speed * OBSTACLE_TOP_SPEED_MULTIPLIER;
    this->y = -this->height;
    this->x = this->middle - this->deviation - this->width / 2;
    this->score = 0;
    this->scoreFlag = true;

    std::cout << "width: " << this->width << "\n";
    std::cout << "height: " << this->height << "\n";
    std::cout << "middle: " << this->middle << "\n";
    std::cout << "deviation: " << this->deviation << "\n";
    std::cout << "speed: " << this->speed << "\n";
}

void Obstacle::initializeObstacle() {
    this->obstacle.setSize(sf::Vector2f(this->width, this->height));
    this->obstacle.setPosition(sf::Vector2f(this->x, this->y));
    this->obstacle.setFillColor(sf::Color::Red);
}

void Obstacle::randomizeLane() {
    int random = rand() % 2;

    switch (random) {
        case 0: 
            this->x = this->middle + this->deviation - this->width / 2;
            this->obstacle.setPosition(sf::Vector2f(this->x, this->y));
            break;
        case 1:
            this->x = this->middle - this->deviation - this->width / 2;
            this->obstacle.setPosition(sf::Vector2f(this->x, this->y));
            break;
        default:
            break;
    }
}

// Public:
void Obstacle::render(sf::RenderTarget* target) {
    target->draw(this->obstacle);
}

void Obstacle::move() {
    this->y += this->speed;

    if (this->y > CARS_DISTANCE_FROM_TOP && this->scoreFlag) {
        this->score++;
        this->scoreFlag = false;
    }

    if (this->y > WINDOW_HEIGHT) {
        if (this->maximum_speed > this->speed) this->speed *= 1.1;
        this->y = -this->height;
        this->randomizeLane();
        this->scoreFlag = true;
    } else {
        this->obstacle.setPosition(sf::Vector2f(this->x, this->y));
    }
}

// get global bounds
const sf::FloatRect Obstacle::getGlobalBounds() const {
    return this->obstacle.getGlobalBounds();
}

// get score
const int Obstacle::getScore() {
    return this->score;
}

// set score
void Obstacle::resetScore() {
    this->score = 0;
}

// set speed
void Obstacle::setSpeed(float speed) {
    this->speed = speed;
}
