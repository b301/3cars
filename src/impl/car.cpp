#include "car.hpp"


// Constructor
Car::Car(float width, float height, float x, float y, float middle, float deviation, sf::Color color, sf::Keyboard::Key movement_key) {
    this->initializeVariables(width, height, x, y, middle, deviation, color, movement_key);
    this->initializeCar(color);
    this->initializeObstacles();
}

// Destructor
Car::~Car() {
    delete this->obstacle;
}

// Private:
void Car::initializeVariables(float width, float height, float x, float y, float middle, float deviation, sf::Color color, sf::Keyboard::Key movement_key) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->middle = middle;
    this->deviation = deviation;
    this->lane = Lane::LEFT;
    this->movement_key = movement_key;

    // std::cout << "width: " << this->width << "\n";
    // std::cout << "height: " << this->height << "\n";
    // std::cout << "x: " << this->x << "\n";
    // std::cout << "y: " << this->y << "\n";
    // std::cout << "middle: " << this->middle / 2 << "\n";
    // std::cout << "deviation: " << this->deviation << "\n";
}

void Car::initializeCar(sf::Color color) {
    this->car.setSize(sf::Vector2f(this->width, this->height));
    this->car.setPosition(sf::Vector2f(this->x, this->y));
    this->car.setFillColor(color);
}

void Car::initializeObstacles() {
    this->obstacle = new Obstacle(this->width, this->height, this->middle, this->deviation, INITIAL_OBSTACLE_SPEED);
}

Lane Car::getLane() {
    return this->lane;
}

void Car::setLane(Lane lane) {
    this->lane = lane;
}

// Public:
void Car::render(sf::RenderTarget* target) {
    target->draw(this->car);
    this->obstacle->move();
    this->obstacle->render(target);
}


// movement
void Car::move(sf::Keyboard::Key key) {
    if (key != this->movement_key) {
        return;
    }
    // std::cout << "move\n";

    if (this->getLane() == Lane::LEFT) {
        // std::cout << "middle: " << this->middle << "\n";
        // std::cout << "deviation: " << this->deviation << "\n";
        // std::cout << "width: " << this->width / 2 << "\n";

        this->x = this->middle + this->deviation - this->width / 2;
        this->car.setPosition(sf::Vector2f(this->x, this->y));
        this->setLane(Lane::RIGHT);
    } else if (this->lane == Lane::RIGHT) {
        // std::cout << "middle: " << this->middle << "\n";
        // std::cout << "deviation: " << this->deviation << "\n";
        // std::cout << "width: " << this->width / 2<< "\n";
        
        this->x = this->middle - this->deviation - this->width / 2;
        this->car.setPosition(sf::Vector2f(this->x, this->y));
        this->setLane(Lane::LEFT);
    }

    // print the cars position
    // std::cout << "x: " << this->x << "\n";
}

// check collison
bool Car::checkCollison() {
    if (this->car.getGlobalBounds().intersects(this->obstacle->getGlobalBounds())) {
        return true;
    }

    return false;
}

// get score
int Car::getScore() {
    return this->obstacle->getScore();
}

// reset score
void Car::reset() {
    this->obstacle->resetScore();
    this->obstacle->setSpeed(INITIAL_OBSTACLE_SPEED);
}