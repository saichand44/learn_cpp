#include <iostream>

// initializing the variables is very important and if not done, they might be
// assigned some random garbage values.

// Constructors are basically methods in a class that automatically get called
// whenever we instantiate a class

class Entity
{
public:
    float x, y;              //-----> if these are not initilalized, they will
                             // pick up garbage values. So efficient way is to
                             // use constructors and add variable iniitialization
                             // in that

    Entity()                //------> constructor: has same name as the class
    {
        x = 0.5f;
        y = 0.9f;
    }

    Entity(float X, float Y)  // we can have multiple definitions of the constructors
    {                         // here we can even pass argument to initialize class variables
        x = X;
        y = Y;
    }

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{   
    Entity e;               // --> uses Entity() constructor
    e.print();         

    Entity e1(1.2f, 3.6f); // --> uses Entity(float X, float Y)  constructor
    e1.print();
}