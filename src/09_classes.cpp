#include <iostream>

// classes --> useful for object oriented programming. By default, the variables
// in a class are private i.e. they are not accessible outside the class definition.
// To make the variables accessible in main(), we need to use 'public'.

class PlayerType1
{
public:
    int x, y;
    int speed;    
};  //-----------------------------> remember this semicolon at the end

void MovePlayer(PlayerType1 &player, int del_x, int del_y)
{
    // Here we need to pass by reference of the object we are trying to move. 
    // In this case,we pass the address of the object and then make modification
    // as needed
    player.x += del_x * player.speed;
    player.y += del_y * player.speed;
}

// The above method of accessig the variable outside the class is unecessary 
// overhead. We can define the function in the class itself, and those functions
// are called methods.

class PlayerType2
{
public:
    int x, y;
    int speed = 0;      // Always intialize undefined values, 
                        // otherwise garbage values are picked

    void MovePlayer(int del_x, int del_y)
    {
        x += del_x * speed;
        y += del_y * speed;
    }
};

void printState(int x, int y)
{
    std::cout << "Player Position:";
    std::cout << x << ", " << y << std::endl;
}

int main()
{   
    // we are using an object called 'Player' and creating an instance of it (instantiation)
    PlayerType1 HollowMike1;
    HollowMike1.x = 5;
    HollowMike1.y = 10;
    printState(HollowMike1.x, HollowMike1.y);
    
    PlayerType2 HollowMike2;
    HollowMike2.x = 5;
    HollowMike2.y = 10;
    HollowMike2.MovePlayer(1, -1);
    printState(HollowMike2.x, HollowMike2.y);
}