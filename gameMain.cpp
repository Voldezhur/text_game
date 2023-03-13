// -------- To Do --------
/*
    1. Make stats and actions scalable to allow for addition of new ones later
    2. Display both the player actions and actions appropriate for the location
    3. Separate classes and main into different files
*/


#include <iostream>


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
// overloading for stat
std::ostream &operator<<(std::ostream &stream, stat obj)
{
    stream << obj.statName << (obj.statName.length() < 8 ? "\t " : " ") << "\t-\t" << obj.value;
    return stream;
}


// character class
class Character
{
public:
    int lvl;
    stat str, end, lck;
    std::string name;

    // constructor
    Character(int lv, int s, int e, int lc)
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
    void printStats()
    {
        std::cout << name << "'s stats:";
        std::cout << "\nLevel\t\t-\t" << lvl;
        
        std::cout << '\n' << str << '\n' << end << '\n' << lck << '\n';
    }
};

// location class
class Location
{
    // pointers to neighbouring locations
    Location* south;
    Location* west;
    Location* north;
    Location* east;

    // other attributes
    std::string flavourText, description;

    bool canForage, canHunt, isHostile;

public:
    // default constructor
    Location()
    {
        south = west = north = east = nullptr;

        flavourText = "placeholderFlavourText";
        description = "placeholderDescription";

        canForage = canHunt = isHostile = true;
    }

    // constructor
    Location(bool _canForage, bool _canHunt, bool _isHostile)
    {
        Location();

        canForage = _canForage;
        canHunt = _canHunt;
        isHostile = _isHostile;
    }


    // ==========================
    // set methods
    
    void setSouth(Location* _south)
    {
        south = _south;
        _south->north = this;
    }

    void setWest(Location* _west)
    {
        west = _west;
        _west->east = this;
    }

    void setNorth(Location* _north)
    {
        north = _north;
        _north->south = this;
    }

    void setEast(Location* _east)
    {
        east = _east;
        _east->west = this;
    }

    void setFlavourText(std::string S)
    {
        flavourText = S;
    }
    
    void setDescription(std::string S)
    {
        description = S;
    }
    

    // ==========================
    // get methods

    std::string getDescription()
    {
        return description;
    }    

    Location* getSouth()
    {
        return south;
    }

    Location* getWest()
    {
        return west;
    }

    Location* getNorth()
    {
        return north;
    }

    Location* getEast()
    {
        return east;
    }


    // ==========================
    // general gameplay methods

    void lookAround()
    {
        std::cout << "You find yourself in " << flavourText << "\n\n";
    }

    void printFlavourText()
    {
        std::cout << flavourText << '\n';
    }
};

// player actions



int main()
{
    // greetings and character creation
    std::cout << "Game started" << "\n\n";
    std::cout << "Default stats:";
    
    Character player(1, 5, 5, 5);


    // stat selection
    int skillPoints = 5;
    
    while(skillPoints)
    {
        std::cout << '\n' << player.str << '\n' << player.end << '\n' << player.lck << "\n\n";
        std::cout << "You have " << skillPoints << " points to spend\n";
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
                player.str++;
                skillPoints--;

            }
            break;
            
            // endurance
            case 2:
            {
                player.end++;
                skillPoints--;
            }
            break;

            // luck
            case 3:
            {
                player.lck++;
                skillPoints--;
            }
            break;

            default:
            {
                std::cout << "\nIncorrect choice\n";
            }
            break;
        }
    }


    // final stat output
    std::cout << "\nFinal stats:";
    std::cout << '\n' << player.str << '\n' << player.end << '\n' << player.lck << "\n\n";

    // skill confirmation
    std::cout << "\nAre these stats ok?\n";

    std::cout << "\nMake a selection:\n";
    std::cout << "y/n\n";

    std::string input;
    
    statConfirmLoop:
    std::cin >> input;

    // check if input is one character long
    while(input.length() != 1)
    {
        std::cout << "\nIncorrect choice\n";
        std::cin >> input;
    }

    switch(input[0])
    {
        case 'y':
        {
            std::cout << "\nStats confirmed\n";
        }
        break;

        case 'n':
        {
            std::cout << "\nTough luck\n";
        }
        break;
        
        default:
        {
            std::cout << "\nIncorrect choice\n";
            goto statConfirmLoop;
        }
        break;
    }
    
    std::cout << "\nLastly, select a name:\n";
    
    // get player name
    std::cin >> std::ws;
    std::getline(std::cin, player.name);

    std::cout << "\nGood luck, " << player.name << "! You'll need it\n\n";


    
    // map creation
    Location* spawnArea = new Location(true, true, false);
    spawnArea->setFlavourText("a clearing of a forest, filled with all types of flowers and wild plants.\nYou sometimes see an occasional squirrel jump from one tree to another");



    // game start
    Location* playerLocation = spawnArea;

    std::cout << "You awaken from your nap in the forest clearing, gather your supplies and prepare to move out\n";    
    std::cout << "What do you do?\n";

    bool mainGameLoop = true;
    // main game loop
    while(mainGameLoop)
    {
        // action selection
        std::cout << "\nMake a selection:\n";

        std::cout << "1. Look around\n2. Show stats\n3. Exit\n";
        int intInput;
        
        actionSelection:
        std::cin >> intInput;

        std::cout << '\n';
        switch(intInput)
        {
            // look around
            case 1:
            {
                playerLocation->printFlavourText();
            }
            break;
            
            // show stats
            case 2:
            {
                player.printStats();
            }
            break;

            // stop game
            case 3:
            {
                mainGameLoop = false;
            }
            break;

            default:
            {
                    std::cout << "\nIncorrect action, try again\n";
                    goto actionSelection;
            }
        }
    }

    // game end
    std::cout << "\nGame ended\n";

    delete spawnArea;
}