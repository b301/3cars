#include "cars_handler.hpp"


// Constructor
CarsHandler::CarsHandler(int cars_count, std::vector<sf::Keyboard::Key> movement_keys, std::vector<sf::Color> colors)
{
    this->initializeCars(cars_count, movement_keys, colors);
}

// Destructor
CarsHandler::~CarsHandler()
{
    for (auto &car : cars)
    {
        delete car;
    }
}

// Private
void CarsHandler::initializeCars(int cars_count, std::vector<sf::Keyboard::Key> movement_keys, std::vector<sf::Color> colors)
{
    if (cars_count < 1)
    {
        throw std::invalid_argument("Cars count must be greater than 0");
    }

    if (cars_count < 26 && cars_count > 5)
    {
        std::cout << cars_count << "cars? you're crazy!" << std::endl;
    }

    if (cars_count > 26)
    {
        throw std::invalid_argument("Cars count must be less than 27");
    }

    if (cars_count > movement_keys.size() && cars_count > colors.size())
    {
        throw std::invalid_argument("Cars count must be equal or less than movement keys count and colors count");
    }

    const float lane_width = WINDOW_WIDTH / cars_count;
    for (int i = 0; i < cars_count; i++)
    {
        cars.push_back(new Car(
            CAR_WIDTH, CAR_HEIGHT, 
            lane_width * (i + 0.5) - (CAR_WIDTH / 2) - CAR_DEVIATION_FROM_MIDDLE, 
            CARS_DISTANCE_FROM_TOP, 
            lane_width * (i + 0.5), 
            CAR_DEVIATION_FROM_MIDDLE,
            colors[i],
            movement_keys[i]
        ));
    }
}


// Public
void CarsHandler::render(sf::RenderTarget* target)
{
    for (auto &car : cars)
    {
        car->render(target);
    }
}

void CarsHandler::move(sf::Keyboard::Key key)
{
    for (auto &car : cars)
    {
        car->move(key);
    }
}

bool CarsHandler::checkCollisons()
{
    for (auto &car : cars)
    {
        if (car->checkCollison())
        {
            return true;
        }
    }
    return false;
}

void CarsHandler::reset()
{
    for (auto &car : cars)
    {
        car->reset();
    }
}

int CarsHandler::getScore()
{
    int score = 0;
    return cars[0]->getScore();
}