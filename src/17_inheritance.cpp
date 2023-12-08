# include <iostream>

// inheritance is useful when we have classes that use certain functions / features
// that are repeated over and over. In this case, we can define a base (parent) class to
// have the repeated features and then individual classes (derived classes) to have
// all the properties of the parent class and new features if needed. This is 
// very imp in OOPs

class Entity
{
public:
    int x, y;

    void Move(float xa, float ya)
    {
        x += xa;
        y += ya;
    }
};

class Player
{
public:
    const char* name;
    int x, y;

    void Move(float xa, float ya)
    {
        x += xa;
        y += ya;
    }

    void PrintName()
    {
        std::cout << name << std::endl;
    } 
};

// In the above definitions,we can see that the Player class has lot of similar 
// properties to the Entity class. So we can inherit those features instead of 
// defining those again in the Player class. Whenever we do "inheritance", the
// derived classes are the superset of parent class i.e they have all the propeties
// of parent class plus extra

class Player2 : public Entity          // -------> class inheritance method
{                                     // This method can access all those that 
public:                               // are public in the Entity class
    const char* name;

    void PrintName()
    {
        std::cout << name << std::endl;
    } 
};


int main()
{
    Player2 player;
    player.name = "HollowMike";
    player.x = 5;
    player.y = 5;
    player.Move(5, 5);
    player.PrintName();
    std::cout << player.x << ", " << player.y << std::endl;
}