#include "CannibalFactory.h"
#include "Cannibal.h"
#include <random>
Enemy *CannibalFactory::createEnemy(std::string atk, std::string def) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniform(30, 8);
    int hp = uniform(gen);

    return new Cannibal(hp, atk, def, 6, "Cannibal " + getName());
}
