// g++ -o gameMain gameMain.cpp Location.cpp Character.cpp && ./gameMain


#include <iostream>
#include "Location.h"
#include "Character.h"


int main()
{
    std::string divider = "\n========================\n\n";
    
    // greetings and character creation
    std::cout << "Game started" << "\n\n";
    std::cout << "Default stats:";
    
    Character player(1, 5, 5, 5);

    std::cout << '\n' << player.str << '\n' << player.end << '\n' << player.lck << "\n\n";
    
    std::cout << "Skip character creation?\ny/n\n";
    char charInput;
    std::cin >> charInput;

    // character creation
    if(charInput == 'n')
    {
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
    }

    // if skipped character creation
    else
    {
        player.name = "player";
    }

    std::cout << "\nGood luck, " << player.name << "! You'll need it" << divider;


    // ===================================
    // map creation
    Location* spawnArea = new Location(true, true, false);
    spawnArea->setFlavourText("a clearing of a forest, filled with all types of flowers and wild plants.\nYou sometimes see an occasional squirrel jump from one tree to another");
    spawnArea->setDescription("a forest clearing");

    Location* town = new Location(true, true, false);
    town->setFlavourText("the main square of a relatively large town, with many shops and vendors scattered about");
    town->setDescription("a town");

    spawnArea->setWest(town);


    // ===================================
    // game start
    Location* playerLocation = spawnArea;

    std::cout << "You awaken from your nap in the forest clearing, gather your supplies and prepare to move out\n";    
    std::cout << "What do you do?";

    bool mainGameLoop = true;
    // main game loop
    while(mainGameLoop)
    {
        // action selection
        std::cout << divider << "Make a selection:\n";

        std::cout << "1. Look around\n2. Show stats\n3. Travel\n4. Exit\n";
        int intInput;
        
        actionSelection:
        std::cin >> intInput;

        std::cout << '\n';
        switch(intInput)
        {
            // look around
            case 1:
            {
                playerLocation->lookAround();
            }
            break;
            
            // show stats
            case 2:
            {
                player.printStats();
            }
            break;

            // movement
            case 3:
            {
                movementSelection:
                std::cout << divider << "Where to?\n";
                std::cout << "1. South\n2. West\n3. East\n4. North\n5. Stop travelling\n";
                
                std::cin >> intInput;

                switch(intInput)
                {
                    // south
                    case 1:
                    {
                        if(playerLocation->getSouth())
                        {
                            playerLocation = playerLocation->getSouth();
                            std::cout << "\nTravelled to " << playerLocation->getDescription() << '\n';
                        }
                        
                        else
                        {
                            std::cout << "There is nothing to the south\n";
                        }
                        
                        goto movementSelection;
                    }
                    break;

                    // west
                    case 2:
                    {
                        if(playerLocation->getWest())
                        {
                            playerLocation = playerLocation->getWest();
                            std::cout << "\nTravelled to " << playerLocation->getDescription() << '\n';                        
                        }

                        else
                        {
                            std::cout << "There is nothing to the west\n";
                        }

                        goto movementSelection;

                    }
                    break;

                    // east
                    case 3:
                    {
                        if(playerLocation->getEast())
                        {
                            playerLocation = playerLocation->getEast();
                            std::cout << "\nTravelled to " << playerLocation->getDescription() << '\n';                        
                        }

                        else
                        {
                            std::cout << "There is nothing to the east\n";
                        }

                        goto movementSelection;
                    }
                    break;

                    // north
                    case 4:
                    {
                        if(playerLocation->getNorth())
                        {
                            playerLocation = playerLocation->getNorth();
                            std::cout << "\nTravelled to " << playerLocation->getDescription() << '\n';
                        }
                        
                        else
                        {
                            std::cout << "There is nothing to the north\n";
                        }

                        goto movementSelection;
                    }
                    break;

                    // stop Travelling
                    case 5:
                    break;

                    default:
                    {
                        std::cout << "\nIncorrect choice, try again\n";
                        goto movementSelection;
                    }
                    break;
                }
            }
            break;

            // stop game
            case 4:
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
    std::cout << divider << "Game ended\n";

    delete spawnArea;
}