#include <iostream>
using namespace std;
#include "Pokemon.h"
#include "AttackPlayStyle.h"
#include "PhysicalAttackPlayStyle.h"
#include "RunPlayStyle.h"
#include "AgileBattleState.h"
#include "NormalBattleState.h"
#include "StrongBattleState.h"
#include <vector>
#include <random>
#include <string>

int main() {
    cout << "                                  ,'\\\n"
            "    _.----.        ____         ,'  _\\   ___    ___     ____\n"
            "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"
            "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"
            " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n"
            "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"
            "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n"
            "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"
            "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"
            "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"
            "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"
            "                                `'                            '-._|" << endl;
    cout << "Welcome to the Pokemon training simulator! To start, select 3 Pokemon to use" << endl;
    cout << "1. Mewtwo" << endl;
    cout << "2. Pikachu" << endl;
    cout << "3. Charizard" << endl;
    cout << "4. Arceus" << endl;
    cout << "5. Jigglypuff" << endl;
    cout << "6. Eevee" << endl;
    cout << "7. Greninja" << endl;
    cout << "8. Venusauar" << endl;
    cout << "9. Alakazam" << endl;
    cout << "10. Diglett" << endl;

    vector<Pokemon*> pokemon;
    pokemon.push_back(new Pokemon("Mewtwo", 100, 20, new AttackPlayStyle()));
    pokemon.push_back(new Pokemon("Pikachu", 30, 10, new PhysicalAttackPlayStyle()));
    pokemon.push_back(new Pokemon("Charizard", 28, 8, new PhysicalAttackPlayStyle()));
    pokemon.push_back(new Pokemon("Arceus", 20, 15, new AttackPlayStyle()));
    pokemon.push_back(new Pokemon("Jigglypuff", 10, 4, new PhysicalAttackPlayStyle()));
    pokemon.push_back(new Pokemon("Eevee", 36, 6, new PhysicalAttackPlayStyle()));
    pokemon.push_back(new Pokemon("Greninja", 47, 8, new PhysicalAttackPlayStyle()));
    pokemon.push_back(new Pokemon("Venusaur", 50, 9, new PhysicalAttackPlayStyle()));
    pokemon.push_back(new Pokemon("Alakazam", 27, 11, new PhysicalAttackPlayStyle()));
    pokemon.push_back(new Pokemon("Diglett", 10, 3, new PhysicalAttackPlayStyle()));

    vector<BattleState*> battleStates;
    battleStates.push_back(new NormalBattleState());
    battleStates.push_back(new AgileBattleState());
    battleStates.push_back(new StrongBattleState());

    vector<Pokemon*> myPokemon;
    for (int i = 0; i < 3; i++) {
        int choice;
        cout << "Select a Pokemon: ";
        cin >> choice;
        if (choice < 1 || choice > 10) {
            cout << "Invalid choice" << endl;
            i--;
        }
        else {
            myPokemon.push_back(pokemon[choice - 1]);
        }
    }

    cout << endl;
    cout << "===================Your starting Pokemon are:====================" << endl;
    for (int i = 0; i < myPokemon.size(); i++) {
        cout << i + 1 << ". " << myPokemon[i]->getName() << "| HP: " << myPokemon[i]->getHp() << " | DMG: " << myPokemon[i]->getDmg() << " | PLay Style: " << myPokemon[i]->getPlayStyle() << endl;
    }
    cout << "==================================================================" << endl << endl;

    cout << "Generating random enemy Pokemon..." << endl << endl;
    vector<Pokemon*> enemyPokemon;
    for (int i = 0; i < 3; i++) {
        int choice = rand() % 10 + 1;
        enemyPokemon.push_back(pokemon[choice - 1]);
    }

    cout << "=====================Your enemy Pokemon are:======================" << endl;
    for (int i = 0; i < enemyPokemon.size(); i++) {
        cout << i + 1 << ". " << enemyPokemon[i]->getName() << "| HP: " << enemyPokemon[i]->getHp() << " | DMG: " << enemyPokemon[i]->getDmg() << " | Play Style: " << enemyPokemon[i]->getPlayStyle() << endl;
    }
    cout << "==================================================================" << endl << endl;

    cout << "Pick a pokemon to start with: " << endl;
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice" << endl;
        return 0;
    }
    Pokemon* currentPokemon = myPokemon[choice - 1];
    Pokemon* currentEnemy = enemyPokemon[0];

    cout << "=====================You have selected:======================" << endl;
    cout << "==============~~~~~~~~~" << currentPokemon->getName() << "!~~~~~~~~~==============" << endl;
    cout << "==================================================================" << endl << endl;

    cout << "Press enter to start the battle!" << endl;
    cin.get();

    while (!myPokemon.empty() && !enemyPokemon.empty()) {
        system("clear");
        cout << "Current Pokemon: " << currentPokemon->getName() << " | HP: " << currentPokemon->getHp() << " | DMG: " << currentPokemon->getDmg() << " | PLay Style: " << currentPokemon->getPlayStyle() << endl;
        cout << "Current Enemy: " << currentEnemy->getName() << " | HP: " << currentEnemy->getHp() << " | DMG: " << currentEnemy->getDmg() << " | PLay Style: " << currentEnemy->getPlayStyle() << endl;
        cout << endl;
        cout << "====================Menu===================" << endl;
        cout << "1. Change Pokemon          2. Attack" << endl;
        cout << "3. Change battle state     4. Change Attack" << endl;
        cout << "5. Run                     6. Quit" << endl;
        cout << "============================================" << endl;
        cout << "What would you like to do? ";
        int selection;
        cin >> selection;
        if (selection < 1 || selection > 6) {
            cout << "Invalid choice" << endl;
            cout << "Press enter to continue" << endl;
            cin.get();
            continue;
        }

        if (selection == 1) {
            for (int i = 0; i < myPokemon.size(); i++) {
                cout << i + 1 << ". " << myPokemon[i]->getName() << "| HP: " << myPokemon[i]->getHp() << " | DMG: " << myPokemon[i]->getDmg() << " | Play Style: " << myPokemon[i]->getPlayStyle() << endl;
            }
            cout << "Pick a pokemon: " << endl;
            int c2;
            cin >> c2;
            if (c2 < 1 || c2 > 3) {
                cout << "Invalid choice" << endl;
                cout << "Press enter to continue" << endl;
                cin.get();
                continue;
            }
            currentPokemon = myPokemon[choice - 1];
            choice = c2;
            cout << "Press enter to continue" << endl;
            cin.ignore();
            cin.get();
        }
        else if (selection == 2) {
            cout << "=====================================BATTLE!====================================" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "=============================| " << currentPokemon->getName() << " | VS | " << currentEnemy->getName() << " |=============================" << endl;
            cout << "--------------------------------------------------------------------------------" << endl << endl;

            if (currentPokemon->getState() == "agile") {
                cout << "Agile state has been selected! Your pokemon will attack twice at 3/4 damage!" << endl;
                currentPokemon->attack();
                currentEnemy->takeDamage(currentPokemon->getDmg());

                if (currentEnemy->getHp() > 0) {
                    currentPokemon->attack();
                    currentEnemy->takeDamage(currentPokemon->getDmg());
                }

                if (currentEnemy->getHp() > 0) {
                    currentEnemy->attack();
                    currentPokemon->takeDamage(currentEnemy->getDmg());
                }
            }
            else if (currentPokemon->getState() == "strong") {
                cout << "Strong state has been selected! Your pokemon will attack at double damage, but miss next turn!" << endl;
                currentPokemon->attack();
                currentEnemy->takeDamage(currentPokemon->getDmg());

                if (currentEnemy->getHp() > 0) {
                    currentEnemy->attack();
                    currentPokemon->takeDamage(currentEnemy->getDmg());

                    if (currentPokemon->getHp() > 0) {
                        cout << "Press enter to continue" << endl;
                        cin.ignore();
                        cin.get();
                        system("clear");

                        cout << "=====================================BATTLE!====================================" << endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                        cout << "=============================| " << currentPokemon->getName() << " | VS | " << currentEnemy->getName() << " |=============================" << endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                        cout << "your Pokemon has missed their attack due to fatigue!" << endl << endl;
                        currentEnemy->attack();
                        currentPokemon->takeDamage(currentEnemy->getDmg());
                    }
                }
            }
            else {
                currentPokemon->attack();
                currentEnemy->takeDamage(currentPokemon->getDmg());

                if (currentEnemy->getHp() > 0) {
                    currentEnemy->attack();
                    currentPokemon->takeDamage(currentEnemy->getDmg());
                }
            }

            if (currentPokemon->getHp() <= 0) {
                myPokemon.erase(myPokemon.begin() + choice - 1);
            }
            if (currentEnemy->getHp() <= 0) {
                int index = 0;
                for (int i = 0; i < enemyPokemon.size(); i++) {
                    if (enemyPokemon[i] == currentEnemy) {
                        index = i;
                        break;
                    }
                }
                enemyPokemon.erase(enemyPokemon.begin() + index);
                currentEnemy = enemyPokemon[0];
            }
            cout << "Press enter to continue" << endl;
            cin.ignore();
            cin.get();
        }
        else if (selection == 3) {
            for (int i = 0; i < battleStates.size(); i++) {
                cout << i + 1 << ". " << battleStates[i]->getBattleStyle() << endl;
            }
            cout << "Pick a battle state: " << endl;
            int c3;
            cin >> c3;
            if (c3 < 1 || c3 > 3) {
                cout << "Invalid choice" << endl;
                cout << "Press enter to continue" << endl;
                cin.ignore();
                cin.get();
                continue;
            }

            if (c3 == 2)


            currentPokemon->selectBattleState(battleStates[c3 - 1]);
        }
        else if (selection == 4) {
            cout << "1. Physical Attack" << endl;
            cout << "2. Attack" << endl;
            cout << "Pick an attack: " << endl;
            int c4;
            cin >> c4;
            if (c4 < 1 || c4 > 3) {
                cout << "Invalid choice" << endl;
                cout << "Press enter to continue" << endl;
                cin.ignore();
                cin.get();
                continue;
            }

            if (c4 == 1) {
                currentPokemon->setPlayStyle(new PhysicalAttackPlayStyle());
            }
            else {
                currentPokemon->setPlayStyle(new AttackPlayStyle());
            }
        }
        else if (selection == 5) {
            currentPokemon->setPlayStyle(new RunPlayStyle());
        }
        else if (selection == 6) {
            cout << "You quit!" << endl;
            return 0;
        }
    }

    if (myPokemon.empty()) {
        cout << "You lost!" << endl;
    }
    else {
        cout << "You won!" << endl;
    }

    for (auto & i : myPokemon) {
        delete i;
    }
    for (auto & i : enemyPokemon) {
        delete i;
    }

    return 0;
}