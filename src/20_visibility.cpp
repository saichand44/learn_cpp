#include <iostream>

// visibility has no effect on the performance of the code at all. It is used 
// for better readability of the code and make it easier to understand what
// variables can be accessed or not outside the scope of the class definition

// Order of visibility: private (lowest) < protected (medium) < public (highest)

class Entity1
{
private:
    int X, Y;

    void print(){}
};

class Entity2
{
public:
    int X, Y;

    void print(){}
};

class Entity3
{
protected:              // -----------> This is bit more lenient than private
    int X, Y;           // as it gives access to the variables or method defined 
                        // in this class across all the dervied class and can be  
    void print(){}      // changed if needed from those classes
public:
    Entity3()
    {
        X=0;
        print();
    }
};

class Player : public Entity3
{
public:
    Player()
    {
        X = 2;
        print();
    }
};