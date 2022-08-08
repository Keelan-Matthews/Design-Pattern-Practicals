#include "JaguarFactory.h"
#include "Jaguar.h"
#include <random>
Enemy *JaguarFactory::createEnemy(std::string atk, std::string def) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(10.0, 3.0);
    int hp = distribution(generator);

    return new Jaguar(hp, atk, def, 4, "Jaguar   " + getName());
}
