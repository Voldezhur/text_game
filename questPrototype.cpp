// -------- To Do --------
/*
    > Short term
    * Show quests for location
    * Make it possible to complete quest
    
    > Not urgent 
    * Automatically assign location ids

    > Long term
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

    int id = 0;

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
        id = 6969;
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
    
    void setId(int* _id)
    {
        id = *_id;
        *_id += 1;
    }

    // ==========================
    // get methods

    int getId()
    {
        return id;
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

    std::string getDescription()
    {
        return description;
    }

    // ==========================
    // general gameplay methods

    void lookAround()
    {
        std::cout << "You find yourself in " << flavourText << "\n\n";
    }

    void showQuests()
    {

    }
};

// quest class
class Quest
{
    std::string objective = "*placeholder objective*";
    std::string name = "*placeholder name*";
    
    int locationId = 0;

    bool isCompleted = false;

public:
    // default constructor
    Quest(){};


    // ==========================
    // set methods

    void setLocationId(int _id)
    {
        locationId = _id;
    }

    void setCompletion(bool _isCompleted)
    {
        isCompleted = _isCompleted;
    }

    void setObjective(std::string _objective)
    {
        objective = _objective;
    }

    void setName(std::string _name)
    {
        name = _name;
    }

    // ==========================
    // get methods

    int getLocationId()
    {
        return locationId;
    }

    bool getCompletion()
    {
        return isCompleted;
    }

    std::string getObjective()
    {
        return objective;
    }

    std::string getName()
    {
        return name;
    }
};


int main()
{
    // variable to allow for assignment of different ids
    int LocationId = 0;    

    // current location of player
    Location* currentLocation;
    

    // ==========================
    // map creation

    // create starting area and set flavour text
    Location* startingArea;
    startingArea->setFlavourText("a clearing of a forest, filled with all types of flowers and wild plants.\nYou sometimes see an occasional squirrel jump from one tree to another");
    startingArea->setId(&LocationId);

    // create area to the west of starting area and set it to the west of starting area
    Location* west;
    west->setFlavourText("*west location placeholder test*");
    west->setId(&LocationId);

    startingArea->setWest(west);


    // ==========================
    // quest creation

    Quest startingQuest;
    startingQuest.setLocationId(startingArea->getId());
    startingQuest.setObjective("Go west");
    startingQuest.setName("Starting quest");


    // ==========================
    // game start
    
    currentLocation = startingArea;
    currentLocation->lookAround();
}