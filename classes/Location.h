#include <string>
#include <iostream>
#include <vector>
#include "Item.h"

class Location
{
    // pointers to neighbouring locations
    Location* south;
    Location* west;
    Location* north;
    Location* east;

    // other attributes
    std::string flavourText, description;

    std::vector<Item> lootTable;



public:
    // default constructor
    Location();

    // constructor
    Location(bool _canForage, bool _canHunt, bool _isHostile);

    // various attributes
    bool canForage, canHunt, isHostile;

    // ==========================
    // set methods
    
    void setSouth(Location* _south);

    void setWest(Location* _west);

    void setNorth(Location* _north);

    void setEast(Location* _east);

    void setFlavourText(std::string S);
    
    void setDescription(std::string S);
    
    template <size_t N>
    void setLootTable(Item (&_lootTable)[N])
    {
        for(int i = 0; i < N; i++)
        {
            lootTable.push_back(_lootTable[i]);
        }
    }


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

    void forage(int luck);
};