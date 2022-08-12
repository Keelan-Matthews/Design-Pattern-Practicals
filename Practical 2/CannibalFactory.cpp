#include "CannibalFactory.h"
#include "Cannibal.h"
#include <random>
Enemy *CannibalFactory::createEnemy(std::string atk, std::string def) {
    std::default_random_engine generator;
    std::mt19937 gen(generator());
    std::uniform_int_distribution<> distribution(30, 8);
    int hp = distribution(gen);

    return new Cannibal(hp, atk, def, 6, "Cannibal " + getName());
}
