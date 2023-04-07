#include <string>
#include <iostream>

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
    Location();

    // constructor
    Location(bool _canForage, bool _canHunt, bool _isHostile);


    // ==========================
    // set methods
    
    void setSouth(Location* _south);

    void setWest(Location* _west);

    void setNorth(Location* _north);

    void setEast(Location* _east);

    void setFlavourText(std::string S);
    
    void setDescription(std::string S);
    

    // ==========================
    // get methods

    std::string getDescription();   

    Location* getSouth();


    Location* getWest();


    Location* getNorth();


    Location* getEast();



    // ==========================
    // general gameplay methods

    void lookAround();

    void printFlavourText();
};