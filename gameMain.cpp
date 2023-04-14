// g++ -o gameMain gameMain.cpp Location.cpp Character.cpp && ./gameMain


#include <iostream>
#include <string>
#include <time.h>
#include "Location.h"
#include "Character.h"


int main()
{
    std::string divider = "\n\n========================\n";
    
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
    spawnArea->setFlavourText("in a clearing of a forest, filled with all types of flowers and wild plants.\nYou sometimes see an occasional squirrel jump from one tree to another");
    spawnArea->setDescription("a forest clearing");


    Location* town = new Location(false, false, false);
    town->setFlavourText("at the main square of a relatively large town, with many shops and vendors scattered about");
    town->setDescription("a town");

    spawnArea->setWest(town);


    Location* dungeon = new Location(true, true, true);    
    dungeon->setFlavourText("in a damp, dark cave. A very unpleasant place to be in.\nYou can see rats, spiders and other critters skittering about as you traverse the cave\nYou also spot something shiny deeper in the darkness");
    dungeon->setDescription("an abandoned dungeon");
    
    spawnArea->setSouth(dungeon);


    Location* lake = new Location(true, false, false);
    lake->setFlavourText("at a small lake. You can see fish in the water.\nYou think you could probably catch some of the fish, provided you had a fishing pole");
    lake->setDescription("a lake");

    town->setNorth(lake);

    
    // ===================================
    // enemy creation
    Character boar(1, 2, 2, 1);
    boar.name = "boar";
    boar.introduction = "A boar rushes at you from the shrubbery!";
    boar.deathMessage = "\nThe boar collapses on the ground, unconsious\n";

    Character skeleton(3, 5, 5, 2);
    skeleton.name = "skeleton";
    skeleton.introduction = "A skeleton shambles towards you!";
    skeleton.deathMessage = "\nThe skeleton fall on the ground in a pile of bones\n";


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

        std::cout << "1. Look around\n2. Show stats\n3. Travel\n4. Hunt\n5. Forage\n";
        std::cout << "\n6. Exit\n";
        int intInput;
        
        actionSelection:
        std::cin >> intInput;

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
                
                if(playerLocation->getSouth()) std::cout << "1. South to " << playerLocation->getSouth()->getDescription() << '\n';
                if(playerLocation->getWest()) std::cout << "2. West to " << playerLocation->getWest()->getDescription() << '\n';
                if(playerLocation->getEast()) std::cout << "3. East to " << playerLocation->getEast()->getDescription() << '\n';
                if(playerLocation->getNorth()) std::cout << "4. North to " << playerLocation->getNorth()->getDescription() << '\n';
                
                std::cout << "\n5. Stop travelling\n";
                
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

            // hunt
            case 4:
            {
                if(playerLocation->canHunt)
                {
                    bool victory = false;

                    // determine which enemy player will fight (based on location)
                    if(playerLocation->getDescription() == "a forest clearing")
                    {
                        victory = player.fight(boar);
                    }
                    else if(playerLocation->getDescription() == "an abandoned dungeon")
                    {
                        victory = player.fight(skeleton);
                    }
                    
                    // hunting combat encounter results
                    if(victory)
                    {
                        std::cout << "\nHunt successful\n";
                    }
                    
                    else
                    {
                        std::cout << "\nHunt unsuccessful\n";

                        if(player.hp <= 0)
                        {
                            mainGameLoop = false;
                        }
                    }
                } 

                else
                {
                    std::cout << "\nCan't hunt at this location\n";
                }
            }
            break;

            // forage
            case 5:
            {
                if(playerLocation->canForage)
                {
                    std::cout << "\nCan't forage in current game version\n";
                }

                else
                {
                    std::cout << "\nCan't forage in this location\n";
                }
            }
            break;

            // stop game
            case 6:
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

    // if player died
    if(player.hp <= 0)
    {
        std::cout << "\nRIP, " << player.name << ", your legacy shall never be forgotten\n";
    }

    // game end

    std::cout << divider << "Game ended\n\n";

    delete spawnArea;
    delete town;
    delete dungeon;
    delete lake;
}