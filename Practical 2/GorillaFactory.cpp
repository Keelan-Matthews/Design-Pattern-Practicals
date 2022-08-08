#include "GorillaFactory.h"
#include "Gorilla.h"
#include <random>
Enemy *GorillaFactory::createEnemy(std::string atk, std::string def) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(4.0, 12.0);
    int hp = distribution(generator);

    return new Gorilla(hp, atk, def, 1, "Gorilla " + getName());
}
