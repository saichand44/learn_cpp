#include <iostream>

// Both stack and heap memory are located in the RAM

// stack --> for local variables and the memory is deleted as soon as the fucntion
// finishes execution

// heap --> dynamic memory allocation; we have to manually allocate memory and delete
// the memory after finishing the tasks. Use this is the object is really big
// (with large number of methods and members) and if we need to retain it outside
// the scope of the braces

// With heap, we need to manually delete the memory but there is a way to delete
// the memory automatically by defining the corresponding function in stack and 
// then calling the delete fucntion internally.. --> [intuition for smart pointers]

class Entity
{
public:
    // Constructor
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    // Destructor
    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};

// This class is called in the stack memory but the Entity ptr is created in the
// heap memory and as soon as the object gets deleted in the stack memory since//
// scope finishes, it calls the destrcutor whihc in turn calls the "delete" command
// for the ptr in heap memory
class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    // constructor
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr)
    {
    }

    // destructor
    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

int main()
{   
    // add additional curly braces to understand the lifetime / scope withing curly braces
    {   
        Entity e; // creating an entity object on the stack memory
    }             // Entity object gets destroyed after getting out of these curly braces

    {
        Entity* e1 = new Entity();
    } // Here the entity object is only created but not destroyed as we didn't call
      // the delete command for the object in heap memory
    
    {
        ScopedPtr e2 = new Entity();
    }// since ScopedPtr gets deleted after the scope, it calls the destructor
     // which in turn calls the "delete" command

    std::cin.get();
}