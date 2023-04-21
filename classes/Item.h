#include <string>

class Item
{    
public:
    Item();
    Item(std::string _name);
    
    std::string name, description;

    int price;
};