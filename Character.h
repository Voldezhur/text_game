#include <string>

// stat struct
struct stat
{
    int value;
    std::string statName;

    void operator++(int)
    {
        value++;
    }

    friend std::ostream &operator<<(std::ostream &stream, stat obj);
};

class Character
{
public:
    int lvl, exp, expMax, hp, dmg;
    stat str, end, lck;
    std::string name, introduction, deathMessage;

    // constructor
    Character(int lv, int s, int e, int lc);

    // prints stats
    void printStats();

    // level up and assign attribute points
    void lvlUp(int points);

    // fight method, returns true, if won, false if lost
    bool fight(Character enemy);
};