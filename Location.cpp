#include "Location.h"

// default constructor
Location::Location()
{
    south = west = north = east = nullptr;

    flavourText = "placeholderFlavourText";
    description = "placeholderDescription";

    canForage = canHunt = isHostile = true;
}

// constructor
Location::Location(bool _canForage, bool _canHunt, bool _isHostile)
{
    Location();

    canForage = _canForage;
    canHunt = _canHunt;
    isHostile = _isHostile;
}


// ==========================
// set methods
    
void Location::setSouth(Location* _south)
{
    south = _south;
    _south->north = this;
}

void Location::setWest(Location* _west)
{
    west = _west;
    _west->east = this;
}

void Location::setNorth(Location* _north)
{
    north = _north;
    _north->south = this;
}

void Location::setEast(Location* _east)
{
    east = _east;
    _east->west = this;
}

void Location::setFlavourText(std::string S)
{
    flavourText = S;
}
    
void Location::setDescription(std::string S)
{
    description = S;
}
    

// ==========================
// get methods

std::string Location::getDescription()
{
    return description;
}    

Location* Location::getSouth()
{
    return south;
}

Location* Location::getWest()
{
    return west;
}

Location* Location::getNorth()
{
    return north;
}

Location* Location::getEast()
{
    return east;
}


// ==========================
// general gameplay methods

void Location::lookAround()
{
    std::cout << "You find yourself in " << flavourText << "\n\n";
}

void Location::printFlavourText()
{
    std::cout << flavourText << '\n';
}