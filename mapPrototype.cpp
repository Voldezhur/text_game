// -------- To Do --------
/*
    * Add quest to starting location

    long term:
    * Figure out how to make movement methods
*/


#include <iostream>


// location class
class Location
{
    // pointers to neighbouring locations
    Location* south = nullptr;
    Location* west = nullptr;
    Location* north = nullptr;
    Location* east = nullptr;

    // other attributes
    std::string flavourText = "*placeholder flavour text*", description = "*placeholder description*";

    bool canForage = false, canHunt = false, isHostile = false;

public:
    // default constructor
    Location(){};

    // constructor
    Location(Location* _south, Location* _west, Location* _north, Location* _east, bool _canForage, bool _canHunt, bool _isHostile)
    {
        south = _south;
        west = _west;
        north = _north;
        east = _west;

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
};


int main()
{
    // current location of player
    Location* currentLocation;
    

    // ==========================
    // map creation

    // create starting area and set flavour text
    Location* startingArea;
    startingArea->setFlavourText("a clearing of a forest, filled with all types of flowers and wild plants.\nYou sometimes see an occasional squirrel jump from one tree to another");

    // create area to the west of starting area and set it to the west of starting area
    Location* west;
    west->setFlavourText("*west location placeholder test*");

    startingArea->setWest(west);

    // ==========================
    // game start
    
    currentLocation = startingArea;
    currentLocation->lookAround();

    // go west
    if(currentLocation->getWest())
    {
        currentLocation = currentLocation->getWest();
    }
    currentLocation->lookAround();

    // go east
    if(currentLocation->getEast())
    {
        currentLocation = currentLocation->getEast();
    }
    currentLocation->lookAround();
}