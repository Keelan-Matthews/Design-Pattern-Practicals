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
    cout << "\u001b[33m                                  ,'\\\n"
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
            "                                `'                            '-._|\u001b[0m" << endl;
    cout << "Welcome to the Pokemon training simulator! To start, select 3 \u001b[33mPokemon\u001b[0m to use" << endl;
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
        cout << "Select a \u001b[33mPokemon\u001b[0m: ";
        cin >> choice;
        if (choice < 1 || choice > 10) {
            cout << "Invalid choice" << endl;
            i--;
        }
        else {
            myPokemon.push_back(pokemon[choice - 1]);
        }
    }
    system("clear");
    cout << endl;
    cout << "===================Your starting \u001b[33mPokemon\u001b[0m are:====================" << endl;
    for (int i = 0; i < myPokemon.size(); i++) {
        cout << i + 1 << ". \u001b[32m" << myPokemon[i]->getName() << "| HP: " << myPokemon[i]->getHp() << " | DMG: " << myPokemon[i]->getDmg() << " | PLay Style: " << myPokemon[i]->getPlayStyle() << "\u001b[0m" << endl;
    }
    cout << "==================================================================" << endl << endl;

    cout << "Generating random enemy \u001b[33mPokemon\u001b[0m..." << endl << endl;
    vector<Pokemon*> enemyPokemon;
    for (int i = 0; i < 3; i++) {
        int choice = rand() % 10 + 1;
        enemyPokemon.push_back(pokemon[choice - 1]);
    }

    cout << "=====================Your enemy \u001b[33mPokemon\u001b[0m are:======================" << endl;
    for (int i = 0; i < enemyPokemon.size(); i++) {
        cout << i + 1 << ". \u001b[34m" << enemyPokemon[i]->getName() << "| HP: " << enemyPokemon[i]->getHp() << " | DMG: " << enemyPokemon[i]->getDmg() << " | Play Style: " << enemyPokemon[i]->getPlayStyle() << "\u001b[0m" << endl;
    }
    cout << "==================================================================" << endl << endl;

    cout << "Pick a \u001b[33mPokemon\u001b[0m to start with: " << endl;
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice" << endl;
        return 0;
    }
    Pokemon* currentPokemon = myPokemon[choice - 1];
    Pokemon* currentEnemy = enemyPokemon[0];

    cout << "=====================You have selected:======================" << endl;
    cout << "==============~~~~~~~~~\u001b[32m" << currentPokemon->getName() << "\u001b[0m!~~~~~~~~~==============" << endl;
    cout << "==================================================================" << endl << endl;

    while (!myPokemon.empty() && !enemyPokemon.empty()) {
        system("clear");
        cout << "Current Pokemon: \u001b[32m" << currentPokemon->getName() << " | HP: " << currentPokemon->getHp() << " | DMG: " << currentPokemon->getDmg() << " | PLay Style: " << currentPokemon->getPlayStyle() << "\u001b[0m" << endl;
        cout << "Current Enemy: \u001b[34m" << currentEnemy->getName() << " | HP: " << currentEnemy->getHp() << " | DMG: " << currentEnemy->getDmg() << " | PLay Style: " << currentEnemy->getPlayStyle() << "\u001b[0m" << endl;
        cout << endl;
        cout << "====================Menu===================" << endl;
        cout << "1. Change \u001b[33mPokemon\u001b[0m          2. Attack" << endl;
        cout << "3. Change battle state     4. Change Attack" << endl;
        cout << "5. Run                     6. \u001b[31mQuit\u001b[0m" << endl;
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
            cout << "Pick a \u001b[33mPokemon\u001b[0m: " << endl;
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
            cout << "=============================| \u001b[32m" << currentPokemon->getName() << "\u001b[0m | VS | \u001b[34m" << currentEnemy->getName() << "\u001b[0m |=============================" << endl;
            cout << "--------------------------------------------------------------------------------" << endl << endl;

            if (currentPokemon->getPlayStyle() == "Run") {
                currentPokemon->attack();
                //Replace current Pokemon with a different pokemon
                int rnd = rand() % 10 + 1;
                while (pokemon[rnd - 1] == currentPokemon) {
                    rnd = rand() % 10 + 1;
                }
                currentPokemon = pokemon[rnd - 1];
            }
            else {
                if (currentPokemon->getState() == "agile") {
                    cout << "Agile state has been selected! Your pokemon will attack twice at 3/4 damage!" << endl;
                    currentPokemon->attack();
                    currentEnemy->takeDamage(currentPokemon->getDmg());

                    if (currentEnemy->getHp() > 0) {
                        currentPokemon->attack();
                        currentEnemy->takeDamage(currentPokemon->getDmg());
                    }

                    currentEnemy->attack();
                    currentPokemon->takeDamage(currentEnemy->getDmg());
                } else if (currentPokemon->getState() == "strong") {
                    cout
                            << "Strong state has been selected! Your pokemon will attack at double damage, but miss next turn!"
                            << endl;
                    currentPokemon->attack();
                    currentEnemy->takeDamage(currentPokemon->getDmg());


                    currentEnemy->attack();
                    currentPokemon->takeDamage(currentEnemy->getDmg());

                    if (currentPokemon->getHp() > 0 && currentEnemy->getHp() > 0) {
                        cout << "Press enter to continue" << endl;
                        cin.ignore();
                        cin.get();
                        system("clear");

                        cout << "====================Menu===================" << endl;
                        cout << "1. Change \u001b[33mPokemon\u001b[0m          2. Attack" << endl;
                        cout << "3. Change battle state     4. Change Attack" << endl;
                        cout << "5. Run                     6. \u001b[31mQuit\u001b[0m" << endl;
                        cout << "============================================" << endl;

                        cout << "=====================================BATTLE!===================================="
                             << endl;
                        cout << "--------------------------------------------------------------------------------"
                             << endl;
                        cout << "=============================| \u001b[32m" << currentPokemon->getName()
                             << "\u001b[0m | VS | \u001b[34m" << currentEnemy->getName()
                             << "\u001b[0m |=============================" << endl;
                        cout << "--------------------------------------------------------------------------------"
                             << endl;
                        cout << "your Pokemon has missed their attack due to fatigue!" << endl << endl;
                        currentEnemy->attack();
                        currentPokemon->takeDamage(currentEnemy->getDmg());
                    } else {
                        cout << currentPokemon->getName() << " has fainted!" << endl;
                    }
                } else {
                    currentPokemon->attack();
                    currentEnemy->takeDamage(currentPokemon->getDmg());

                    currentEnemy->attack();
                    currentPokemon->takeDamage(currentEnemy->getDmg());
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