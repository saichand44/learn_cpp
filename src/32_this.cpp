#include <iostream>

// "this" keyword can be used inside the "method" fucntions inside a call to call
// that particular instance of the object. "this" is a pointer

// Use forward declaration...
class Entity;
void PrintEntity(Entity* e);

class Entity
{
public:
    int x, y;

    Entity(int x, int y)
    {
        // Here if we directly initiate the values of the fucntion arguments
        // to the members of the class, then we have x=x and y=y which doesn't make
        // sense. So we use "this" to refer to the object of the class and then
        // access the memebers of the object
        this->x = x; // -> operator is used for dereferencing (simila to (*this).x)
        this->y = y;

        PrintEntity(this);
    }
};

void PrintEntity(Entity* e)
{
    // Print stuff!
}

int main()
{
    // Nothing to see here!
}