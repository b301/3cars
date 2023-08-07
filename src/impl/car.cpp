#include "car.hpp"

// Constructor
Car::Car(float width, float height, float x, float y, float middle, float deviation, sf::Color color, sf::Keyboard::Key movement_key)
{
    this->initializeVariables(width, height, x, y, middle, deviation, color, movement_key);
    this->initializeCar(color);
    this->initializeEntities();
}

// Destructor
Car::~Car()
{
    delete this->obstacle;
}

// Private:
void Car::initializeVariables(float width, float height, float x, float y, float middle, float deviation, sf::Color color, sf::Keyboard::Key movement_key)
{
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->middle = middle;
    this->deviation = deviation;
    this->lane = Lane::LEFT;
    this->movement_key = movement_key;
}

void Car::initializeCar(sf::Color color)
{
    this->car.setSize(sf::Vector2f(this->width, this->height));
    this->car.setPosition(sf::Vector2f(this->x, this->y));
    this->car.setFillColor(color);
}

void Car::initializeEntities()
{
    this->obstacle = new Obstacle(OBSTACLE_WIDTH, OBSTACLE_HEIGHT, this->middle, this->deviation, INITIAL_OBSTACLE_SPEED);
    this->food = new Food(OBSTACLE_WIDTH, OBSTACLE_HEIGHT, this->middle, this->deviation, INITIAL_OBSTACLE_SPEED);
}

Lane Car::getLane()
{
    return this->lane;
}

void Car::setLane(Lane lane)
{
    this->lane = lane;
}

// Public:
void Car::render(sf::RenderTarget *target)
{
    target->draw(this->car);
    this->obstacle->move();
    this->obstacle->render(target);
    this->food->move(this->car);
    this->food->render(target);
}

// movement
void Car::move(sf::Keyboard::Key key)
{
    if (key != this->movement_key)
    {
        return;
    }
    // std::cout << "move\n";

    if (this->getLane() == Lane::LEFT)
    {
        this->x = this->middle + this->deviation - this->width / 2;
        this->car.setPosition(sf::Vector2f(this->x, this->y));
        this->setLane(Lane::RIGHT);
    }
    else if (this->lane == Lane::RIGHT)
    {
        this->x = this->middle - this->deviation - this->width / 2;
        this->car.setPosition(sf::Vector2f(this->x, this->y));
        this->setLane(Lane::LEFT);
    }
}

// check collison
bool Car::checkCollison()
{
    if (this->car.getGlobalBounds().intersects(this->obstacle->getGlobalBounds()))
    {
        return true;
    }

    return false;
}

// get score
int Car::getScore()
{
    return this->food->getScore();
}

// reset score
void Car::reset()
{
    this->obstacle->setSpeed(INITIAL_OBSTACLE_SPEED);
    this->food->setSpeed(INITIAL_FOOD_SPEED);
    this->food->resetScore();
}