#include <iostream>

int getSizeOf(const int (&_nums)[])
{
    return sizeof(&_nums) / sizeof(int);
}


int main()
{
    const int nums[] = {1, 2, 3};
    
    std::cout << getSizeOf(nums);
}