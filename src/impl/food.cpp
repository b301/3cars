#include "food.hpp"

// Constructor
Food::Food(float width, float height, float middle, float deviation, float speed)
{
    this->initializeVariables(width, height, middle, deviation, speed);
    this->initializeFood();
    this->randomizeLane();
}

// Destructor
Food::~Food()
{
}

// Private
void Food::initializeVariables(float width, float height, float middle, float deviation, float speed)
{
    this->width = width;
    this->height = height;
    this->middle = middle;
    this->deviation = deviation;
    this->speed = speed;
    this->maximum_speed = speed * FOOD_TOP_SPEED_MULTIPLIER;
    this->y = -this->height + 300.f;
    this->x = this->middle - this->deviation - this->width / 2;
    this->score = 0;
    this->scoreFlag = false;
}

void Food::initializeFood()
{
    this->food.setRadius(FOOD_WIDTH / 2);
    this->food.setPosition(sf::Vector2f(this->x, this->y));
    this->food.setFillColor(sf::Color::Red);
}

void Food::randomizeLane()
{
    int random = rand() % 2;

    switch (random)
    {
    case 0:
        this->x = this->middle + this->deviation - this->width / 2;
        this->food.setPosition(sf::Vector2f(this->x, this->y));
        break;
    case 1:
        this->x = this->middle - this->deviation - this->width / 2;
        this->food.setPosition(sf::Vector2f(this->x, this->y));
        break;
    default:
        break;
    }
}

// Public:
void Food::render(sf::RenderTarget *target)
{
    target->draw(this->food);
}

void Food::move(sf::RectangleShape &car)
{
    this->y += this->speed;

    if (car.getGlobalBounds().intersects(this->food.getGlobalBounds()) && !this->scoreFlag)
    {
        this->score++;
        this->scoreFlag = true;
        this->food.setFillColor(sf::Color::Transparent);
    }

    // if the food is lower than the car then reset the score
    if (this->y > car.getPosition().y + car.getSize().y && !this->scoreFlag)
    {
        this->resetScore();
    }

    if (this->y > WINDOW_HEIGHT)
    {
        if (this->maximum_speed > this->speed)
            this->speed *= ENTITY_SPEED_MULTIPLIER;

        this->y = -ENTITY_START_HEIGHT;
        this->randomizeLane();
        this->food.setFillColor(sf::Color::Red);
        this->scoreFlag = false;
    }
    else
    {
        this->food.setPosition(sf::Vector2f(this->x, this->y));
    }
}

const sf::FloatRect Food::getGlobalBounds() const
{
    return this->food.getGlobalBounds();
}

const int Food::getScore()
{
    return this->score;
}

void Food::resetScore()
{
    this->score = 0;
}

void Food::setSpeed(float speed)
{
    this->speed = speed;
}
