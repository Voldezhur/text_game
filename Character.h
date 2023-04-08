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
    int lvl;
    stat str, end, lck;
    std::string name;

    // constructor
    Character(int lv, int s, int e, int lc);

    // prints stats
    void printStats();
};