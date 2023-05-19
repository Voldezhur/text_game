#include "Character.h"
#include <iostream>

std::string divider = "\n\n========================\n";


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
    expMax = 100;
    str.value = s;
    end.value = e;
    lck.value = lc;

    hp = end.value * 10;
    dmg = str.value * 2;

    str.statName = "Strength";
    end.statName = "Endurance";
    lck.statName = "Luck";

    name = "*placeholderName*";
    introduction = "*placeholderIntroduction*";
    deathMessage = "*placeholderDeathMessage*";
}

// prints stats
void Character::printStats()
{
    std::cout << name << "'s stats:";
    std::cout << "\nLevel\t\t-\t" << lvl;
    std::cout << "\nExperience\t-\t" << exp << " / " << expMax;
      
    std::cout << "\n\n" << str << '\n' << end << '\n' << lck;

    std::cout << "\n\nHealth\t\t-\t" << hp << '\n';
    std::cout << "Damage\t\t-\t" << dmg;
}

// level up and assign attribute points
void Character::lvlUp(int points)
{
    std::cout << divider << "You feel yourself becoming stronger!";

    while(points)
        {
            std::cout << '\n' << str << '\n' << end << '\n' << lck << "\n\n";
            std::cout << "You have " << points << " points to spend\n";
            std::cout << "\nMake a selection:\n";

            std::cout << "1. Add point to strength\n2. Add point to Endurance\n3. Add point to luck\n";

            int input;
            std::cin >> input;
            // player choice of stat
            switch(input)
            {
                // strength
                case 1:
                {
                    str++;
                    points--;

                }
                break;
                
                // endurance
                case 2:
                {
                    end++;
                    points--;
                }
                break;

                // luck
                case 3:
                {
                    lck++;
                    points--;
                }
                break;

                default:
                {
                    std::cout << "\nIncorrect choice\n";
                }
                break;
            }
        }
}

// fight method, returns true, if won, false if lost
bool Character::fight(Character enemy)
{
    std::cout << '\n' << enemy.introduction << '\n';

    bool fightLoop = true;

    // main fight loop
    while(hp > 0 && enemy.hp > 0 && fightLoop)
    {
        std::cout << "\nYour hp - " << hp << '\n';
        std::cout << enemy.name << "'s hp - " << enemy.hp << '\n';

        // player's turn
        std::cout << "Make a selection:\n";

        std::cout << "1. Attack\n2. Flee\n";
        int intInput;
        
        actionSelection:
        std::cin >> intInput;

        // player choice
        switch(intInput)
        {
            // Attack
            case 1:
            {
                enemy.hp -= dmg;
                std::cout << "\nAttacked " << enemy.name << " for " << dmg << " damage!\n";
                std::cout << enemy.name << "'s health is now " << enemy.hp << '\n';
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
        if(enemy.hp > 0)
        {
            hp -= enemy.dmg;
            std::cout << enemy.name << " attacks " << name << " for " << enemy.dmg << " damage!\n";
            std::cout << name << "'s health is now " << hp << '\n';
        }
    }

    // died
    if(hp <= 0)
    {
        return false;
    }

    // fled
    else if(hp > 0 && enemy.hp > 0)
    {
        std::cout << "'\nFled, like a coward\n";
        return false;
    }

    // won
    else
    {
        exp += enemy.lvl * 20;
        
        std::cout << '\n' << enemy.name << " collapses on the ground, unconsious\n";
        std::cout << '\n' << name << " emerges victorious!\n";
        std::cout << "You recieve " << enemy.lvl * 20 << " experience\n";

        // lvlup if neccessary
        int points = 0;

        while(exp >= expMax)
        {
            exp -= expMax;
            expMax += 10;
            points++;
        }

        if(points > 0)
        {
            lvlUp(points);
        }

        return true;
    }
}