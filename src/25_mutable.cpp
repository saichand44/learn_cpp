#include <iostream>
#include <string.h>

// mutable is basically used when we have to change the variables in the "const"
// method of a class where we cannot change any variables at all. Using "mutable"
// for a particular variable can basically allow only that to change even in the
// "const" defined method of a class

// mutable is also used in the lambda fucntions

class Entity
{
private:
    std::string m_Name;
    mutable int debugCounter = 0;
public:
    const std::string& GetName() const
    {   
        // If we want to modify or keep track of how many times we are entering this
        // method, then we need a counter but we cannot update any variables within
        // this class method as it is defined as "const". A work around is to 
        // define that particular variable that has to be changed to "mutable".
        debugCounter++;

        // This string cannot be modified as the method is defined as const!
        return m_Name;
    }
};

int main()
{
    const Entity e;   // since we defined "const" here, we can only access "const" class methods
    e.GetName();
}