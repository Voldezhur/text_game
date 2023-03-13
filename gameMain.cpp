// -------- To Do --------
/*
    1. Make stats and actions scalable to allow for addition of new ones later
    2. Display both the player actions and actions appropriate for the location

*/


#include <iostream>


// stat struct
struct stat
{
    int value;
    std::string statName;
};

// character class
class Character
{
public:
    int lvl;
    stat str, end, lck;
    std::string name;

    int stats[3] = {str.value, end.value, lck.value};

    
    // prints stats
    void printStats()
    {
        std::cout << name << "'s stats:";
        std::cout << "\nLevel\t-\t" << lvl;

        
        for(int i = 0; i <= 3; i++)
        {
            std::cout << '\n';
        }
    }

    // constructor
    Character(int lv, int s, int e, int lc)
    {
        lvl = lv;
        str.value = s;
        end.value = e;
        lck.value = lc;
    }
};

// location class
class Location
{
public:
    // pointers to neighbouring locations
    Location* south;
    Location* west;
    Location* north;
    Location* east;

    // other attributes
    std::string flavourText, description;

    bool canForage, canHunt, isHostile;
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
        std::cout << "\nStrength\t-\t" << player.str << "\nEndurance\t-\t" << player.end << "\nLuck\t\t-\t" << player.lck << "\n\n";
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
    std::cout << "\nStrength\t-\t" << player.str << "\nEndurance\t-\t" << player.end << "\nLuck\t\t-\t" << player.lck << "\n\n";

    // skill confirmation
    std::cout << "\nAre these stats ok?\n";

    std::cout << "\nMake a selection:\n";
    std::cout << "y/n\n";

    std::string input;
    
    // check if input is one character long
    statConfirmLoop:
    std::cin >> input;

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
    Location spawnArea;
    spawnArea.isHostile = false;
    spawnArea.flavourText = "a clearing of a forest, filled with all types of flowers and wild plants.\nYou sometimes see an occasional squirrel jump from one tree to another";



    // game start
    Location playerLocation = spawnArea;

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
                playerLocation.printFlavourText();
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
}