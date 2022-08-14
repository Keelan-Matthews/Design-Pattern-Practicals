#pragma once
#include "Enemy.h"
#include <ctime>
class EnemyFactory {
public:
    EnemyFactory()= default;
    virtual ~EnemyFactory()= default;
    virtual Enemy* createEnemy(std::string atk, std::string def) = 0;
protected:
    static std::string getName() {
        std::string names[] = {"Infant ","General","Wizard ","Undead ", "Warrior", "Wyvern ", "Cyborg ", "Rune   ", "Angel  ", "Demon  ", "Dragon ", "Giant  ", "Goblin ", "Golem  ", "Harpy  ", "Hobbit ", "Human  ", "Imp    ", "Lizard ", "Mage   ", "Mummy  ", "Naga   ", "Ogre   ", "Orc    ", "Phoenix", "Priest ", "Spider ", "Troll  ", "Vampire", "Warlock", "Witch  ", "Zombie "};
        return names[rand() % (sizeof(names) / sizeof(names[0]))];
    }
};