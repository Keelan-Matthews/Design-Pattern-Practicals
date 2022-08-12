#include "GorillaFactory.h"
#include "Gorilla.h"
#include <random>
Enemy *GorillaFactory::createEnemy(std::string atk, std::string def) {
    std::default_random_engine generator;
    std::mt19937 gen(generator());
    std::uniform_int_distribution<> distribution(4, 12);
    int hp = distribution(gen);

    return new Gorilla(hp, atk, def, 1, "Gorilla  " + getName());
}
