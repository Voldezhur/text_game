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
    str.value = s;
    end.value = e;
    lck.value = lc;

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