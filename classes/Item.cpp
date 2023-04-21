#include "Item.h"


Item::Item()
{
    name = "*placeholderName*";
    description = "*placeholderDescription*";
    price = 0;
}

Item::Item(std::string _name)
{
    name = _name;
    description = "*placeholderDescription*";
    price = 0;
}