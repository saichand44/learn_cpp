#include <iostream>

// const basically doesn't allow variables or even variables in methods in classes 
// to change. But there are ways to actually modify the variables even if they
// are defined as "const".

class Entity
{
private:
    int m_X, m_Y;
public:
    int GetX() const
    {   
        // since we defined "const" at the end of the fucntions definition, we 
        // cannot modify the variables. This works ONLY in classes.
        // m_X = 2; // doesn't work!!!
        return m_X;
    }

    int GetX()
    {   
        // This is like a normal method where we can modify the variables
        m_X = 2;
        return m_X;
    }
};

void PrintEntity(const Entity& e)
{   
    // Since we defined the argument as "const" before the address, it means we 
    // cannot change the contents of the Entity "e", but we can change the address

    // in order for the "const" Entity to access methods that do not change variables.
    // we need to define "const" in the methods of the class. Otherwise, the below
    // definition will aceess the method that doesn't have "const". So technically,
    // we can have two fucntions that have same name but accessible depending on
    // context..
    
    std::cout << e.GetX() << std::endl;
}
int main()
{
    const int MAX_AGE = 90;  // means there is a constant variable that doesn't change

    // "const" applied to pointers

    // CASE1:
    // 1) allow only changing the address of the pointer
    // 2) doesn't allow the contents of the pointer to be changed
    const int* a = new int;    // --> assigning variables in the heap memory

    // *a = 2; doesn't work as we are not allowed to changed the contents
    a = (int*)&MAX_AGE; // allowed since we can change the address the pointer is pointing

    // CASE2:
    // 1) doesn't allow  changing the address of the pointer
    // 2) only allow the contents of the pointer to be changed
    int* const b = new int;    // --> assigning variables in the heap memory

    *b = 2; // works as we are allowed to changed the contents
    // b = (int*)&MAX_AGE; // not allowed since we can't change the address the pointer is pointing

    // CASE3:
    // This doesn't allow the address and also the data to be changed
    const int* const c = new int;


}