#include "SnakeFactory.h"
#include "Snake.h"
#include <random>
Enemy *SnakeFactory::createEnemy(std::string atk, std::string def) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(6.0, 1.0);
    int hp = distribution(generator);

    return new Snake(hp, atk, def, 2, "Snake " + getName());
}
