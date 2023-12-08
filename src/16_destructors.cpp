#include <iostream>

// destructors are basically the opposite of constructors. These are used to 
// destroy / release memory of the variables that were initialized when the 
// class object was created. The memory could be freed either from stack or heap
// depending on whether we defined the variales in the function (stack) or directly
// (heap)

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
        std::cout << "Created Variables!" << std::endl;
    }

    Entity(float X, float Y)  // we can have multiple definitions of the constructors
    {                         // here we can even pass argument to initialize class variables
        x = X;
        y = Y;
    }

    ~Entity()
    {
        // notice the tilda symbol before the name. Destructors also have the same
        // name as the class except they have "~" as well before the name. 

        std::cout << "Destroyed Variables!" << std::endl;
    }

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

void Function()
{
    Entity e;
    e.print();
}

int main()
{   
    Function();
}