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
#include <cstdlib>
#include <random>

int main() {
    system("clear");
    std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------\u001b[38;5;48mWELCOME TO ADVENTURE ISLAND\u001b[0m------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Please enter your name:" << std::endl;

    std::string name;
    std::cin >> name;

    std::cout << "\u001b[38;5;93m" << name << "\u001b[0m, this dice will be used to determine the number of members in your squad. Please roll by pressing \u001b[38;5;48menter\u001b[0m:" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << "Rolling dice..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    srand(time(nullptr));
    int teamCount = rand() % 6 + 2;
    std::cout << "Dice rolled! You have " << teamCount << " members in your squad." << std::endl << std::endl;

    //  Initialize all squad members - Prototype method
    std::vector<SquadMember*> squad;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniform(5, 15);
    int damage = uniform(gen);

    SquadMember *soldier = new Soldier(10,damage,"Military Rifle","Flashbang");
    for (int i = 0; i < teamCount; i++){
        SquadMember *member = soldier->clone();
        squad.push_back(member);
    }

    std::cout << "Your squad is ready! They are as follows:" << std::endl;
    for (int i = 0; i < squad.size(); i++){
        std::cout << "Squad Member " << i + 1 << ": " << squad[i]->getName() << std::endl;
    }

    std::cout << std::endl << "Press \u001b[38;5;48menter\u001b[0m to generate enemies" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Initialize enemies - Factory method
    std::cout << "---------------------" << std::endl <<std::endl;
    std::cout << "Generating enemies..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::vector<Enemy*> enemies;
    EnemyFactory *snakeFactory = new SnakeFactory();
    EnemyFactory *jaguarFactory = new JaguarFactory();
    EnemyFactory *gorillaFactory = new GorillaFactory();
    EnemyFactory *cannibalFactory = new CannibalFactory();

    for (int i = 0; i < teamCount; i++){
        Enemy *enemy = nullptr;
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

    std::cout << "Press \u001b[38;5;48many key\u001b[0m to begin the game" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Beginning game..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    //Battle
    int enemycount = teamCount;
    int counter = teamCount;
    while (!squad.empty() && !enemies.empty()) {
        system("clear");
        std::cout << "\u001b[38;5;48m------------------------------------------------------------------------------------------------------------------\u001b[0m" << std::endl;
        std::cout << "\u001b[38;5;48m---------------------------------------============BATTLE STATUS============--------------------------------------\u001b[0m" << std::endl;
        std::cout << "\u001b[38;5;48m------------------------------------------------------------------------------------------------------------------\u001b[0m" << std::endl << std::endl;

        std::cout << "Squad:                                             Enemies:                                  ";
        std::cout << "Members left ";
        for (int i = 0; i < teamCount; i++)
            std::cout << "\u001b[38;5;93m❤\u001b[0m ";
        std::cout << "\n";
        std::cout << "                                                                                         Enemies left ";
        for (int i = 0; i < enemycount; i++)
            std::cout << "\u001b[38;5;93m❤\u001b[0m ";
        std::cout << "\n\n";

        for (int i = 0; i < counter; i++) {
            if (squad.size() > i)
                std::cout << i+1 << ". " << squad[i]->getName() << "   " << squad[i]->getHP() << " HP | " << squad[i]->getDamage() << " DMG                  ";
            else
                std::cout << "\u001b[38;5;196m------Deceased------\u001b[0m" << "                                 ";

            if (enemies.size() > i)
                std::cout << i+1 << ". " << enemies[i]->getName() << "   " << enemies[i]->getHP() << " HP | " << enemies[i]->getDMG() << " DMG" << std::endl;
            else
                std::cout << "\u001b[38;5;196m------Deceased------\u001b[0m" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Pick a squad member to fight with:" << std::endl;
        int index;
        std::cin >> index;
        index--;
        while (index < 0 || index >= squad.size()) {
            std::cout << "Invalid index" << std::endl;
            std::cin >> index;
            index--;
        }

        std::cout << "Pick an enemy to fight against:" << std::endl;
        int enemyIndex;
        std::cin >> enemyIndex;
        enemyIndex--;
        while (enemyIndex < 0 || enemyIndex >= enemies.size()) {
            std::cout << "Invalid index" << std::endl;
            std::cin >> enemyIndex;
            enemyIndex--;
        }

        std::cout << "Battle started!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "Battle results:" << std::endl;
        enemies[enemyIndex]->attack(squad[index]);
        if (squad[index]->getHP() <= 0) {
            std::cout << squad[index]->getName() << " has been \u001b[38;5;196mkilled!\u001b[0m" << std::endl;
            delete squad[index];
            squad[index] = nullptr;
            squad.erase(squad.begin() + index);
            teamCount--;
        } else {
            std::cout << enemies[enemyIndex]->getName() << " has been \u001b[38;5;196mkilled!\u001b[0m" << std::endl;
            delete enemies[enemyIndex];
            enemies[enemyIndex] = nullptr;
            enemies.erase(enemies.begin() + enemyIndex);
            enemycount--;
        }
        std::cout << std::endl << "Press \u001b[38;5;48menter\u001b[0m to continue" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    delete jaguarFactory;
    delete snakeFactory;
    delete gorillaFactory;
    delete cannibalFactory;
    for (auto & member : squad) {
        delete member;
    }
    for (auto & enemy : enemies) {
        delete enemy;
    }

    std::cout << "\n" << std::endl;
    if (squad.empty()) {
        std::cout << "You have been defeated, \u001b[38;5;93m" << name << "\u001b[0m!" << std::endl;
    } else {
        std::cout << "You have defeated all enemies! Well done \u001b[38;5;93m" << name << "\u001b[0m" << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------THANK YOU FOR PLAYING---------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------\n" << std::endl;

    return 0;
}

