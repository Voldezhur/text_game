#include "Character.h"
#include <iostream>

// overloading for stat
std::ostream &operator<<(std::ostream &stream, stat obj)
{
    stream << obj.statName << (obj.statName.length() < 8 ? "\t " : " ") << "\t-\t" << obj.value;
    return stream;
}


// constructor
Character::Character(int lv, int s, int e, int lc)
{
    lvl = lv;
    exp = 0;
    str.value = s;
    end.value = e;
    lck.value = lc;

    hp = end.value * 10;
    dmg = str.value * 2;

    str.statName = "Strength";
    end.statName = "Endurance";
    lck.statName = "Luck";
}

// prints stats
void Character::printStats()
{
    std::cout << name << "'s stats:";
    std::cout << "\nLevel\t\t-\t" << lvl;
      
    std::cout << '\n' << str << '\n' << end << '\n' << lck << '\n';
}

// fight method, returns true, if won, false if lost
bool Character::fight(Character* enemy)
{
    std::cout << "\nAttacked " << enemy->name << "!\n\n";

    bool fightLoop = true;

    while(hp > 0 && enemy->hp > 0 && fightLoop)
    {
        std::cout << "\nYour hp - " << hp << '\n';
        std::cout << enemy->name << "'s hp - " << enemy->hp << '\n';

        // player's turn
        std::cout << "Make a selection:\n";

        std::cout << "1. Attack\n2. Flee\n";
        int intInput;
        
        actionSelection:
        std::cin >> intInput;
        std::cout << '\n';

        // player choice
        switch(intInput)
        {
            // Attack
            case 1:
            {
                enemy->hp -= dmg;
                std::cout << "\nAttacked " << enemy->name << " for " << dmg << " damage!\n";
                std::cout << enemy->name << "'s health is now " << enemy->hp << '\n';
            }
            break;

            // flee
            case 2:
            {
                fightLoop = false;
            }
            break;
        }


        // enemy's turn
        if(enemy->hp > 0)
        {
            hp -= enemy->dmg;
            std::cout << enemy->name << " attacks " << name << " for " << enemy->dmg << " damage!\n";
            std::cout << name << "'s health is now " << hp << '\n';
        }
    }

    if(hp <= 0)
    {
        std::cout << '\n' << name << " collapses on the ground, unconsious\n";
        return false;
    }

    else if(hp > 0 && enemy->hp > 0)
    {
        std::cout << "'\nFled, like a coward\n";
        return false;
    }

    else
    {
        std::cout << '\n' << name << " emerges victorious!\n";
        return true;
    }
}