#include "CannibalFactory.h"
#include "Cannibal.h"
#include <random>
Enemy *CannibalFactory::createEnemy(std::string atk, std::string def) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(30.0, 8.0);
    int hp = distribution(generator);

    return new Cannibal(hp, atk, def, 6, "Cannibal " + getName());
}
