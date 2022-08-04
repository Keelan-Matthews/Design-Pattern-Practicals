#include <iostream>
#include "EnemyFactory.h"
#include "Soldier.h"
#include "SnakeFactory.h"
#include "JaguarFactory.h"
#include "GorillaFactory.h"
#include "CannibalFactory.h"
#include <chrono>
#include <thread>
#include <vector>
int main() {
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "-------------------------WELCOME TO ADVENTURE ISLAND------------------------" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Please enter your name:" << std::endl;

    std::string name;
    std::cin >> name;

    std::cout << name << ", the following dice will be used to determine the number of members in your squad. Please roll by pressing any key:" << std::endl;
    std::cin.get();
    std::cout << "Rolling dice..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    srand ( time(nullptr) );
    int teamCount = rand() % 6;
    std::cout << "Dice rolled! You have " << teamCount << " members in your squad." << std::endl << std::endl;

    //  Initialize all squad members - Prototype method
    std::vector<SquadMember*> squad;
    SquadMember *soldier = new Soldier(10,5,"Military Rifle","Flashbang");
    for (int i = 0; i < teamCount; i++){
        SquadMember *member = soldier->clone();
        squad.push_back(member);
    }

    std::cout << "Your squad is ready! They are as follows:" << std::endl;
    for (int i = 0; i < squad.size(); i++){
        std::cout << "Squad Member " << i + 1 << ": " << squad[i]->getName() << std::endl << std::endl;
    }

    //Initialize enemies - Factory method
    std::cout << "Generating enemies..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::vector<Enemy*> enemies;
    EnemyFactory *snakeFactory = new SnakeFactory();
    EnemyFactory *jaguarFactory = new JaguarFactory();
    EnemyFactory *gorillaFactory = new GorillaFactory();
    EnemyFactory *cannibalFactory = new CannibalFactory();
    for (int i = 0; i < teamCount; i++){
        Enemy *enemy = nullptr;
        srand ( time(nullptr) );
        switch (rand() % 4) {
            case 0:
                enemy = snakeFactory->createEnemy("Bite","Curl");
                break;
            case 1:
                enemy = jaguarFactory->createEnemy("Claw","Hiss");
                break;
            case 2:
                enemy = gorillaFactory->createEnemy("Fists","Jump away");
                break;
            case 3:
                enemy = cannibalFactory->createEnemy("Maul","Run away");
                break;
        }
        enemies.push_back(enemy);
    }

    std::cout << "Enemies generated! They are as follows:" << std::endl;
    for (auto & enemy : enemies){
        std::cout << enemy->getName() << ":        HP: " << enemy->getHP() << std::endl;
    }

    return 0;
}
