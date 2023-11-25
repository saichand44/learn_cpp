#include <iostream>

// Structs are essentially the same as classes except the default visibility of
// the variables and the methods is public

struct PlayerType1
{
    int x, y;
    int speed;    
};  //-----------------------------> remember this semicolon at the end

void printState(int x, int y)
{
    std::cout << "Player Position:";
    std::cout << x << ", " << y << std::endl;
}

int main()
{
    PlayerType1 HollowMike1;
    HollowMike1.x = 5;
    HollowMike1.y = 10;
    printState(HollowMike1.x, HollowMike1.y);
}