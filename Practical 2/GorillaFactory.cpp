#include "GorillaFactory.h"
#include "Gorilla.h"
#include <random>
Enemy *GorillaFactory::createEnemy(std::string atk, std::string def) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniform(4, 12);
    int hp = uniform(gen);

    return new Gorilla(hp, atk, def, 1, "Gorilla  " + getName());
}
