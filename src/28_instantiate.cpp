#include <iostream>
#include <string.h>

// Both stack and heap memory are located in the RAM

// stack --> for local variables and the memory is deleted as soon as the fucntion
// finishes execution

// heap --> dynamic memory allocation; we have to manually allocate memory and delete
// the memory after finishing the tasks. Use this is the object is really big
// (with large number of methods and members) and if we need to retain it outside
// the scope of the braces

// we can instantiate class objects in stack and heap 

class Entity
{
private:
    std::string m_Name;
public:
    Entity()
        : m_Name("Unknown")
    {
    }

    Entity(const std::string& name)
        : m_Name(name)
    {
    }

    const std::string GetName() const
    {
     return m_Name;
    }

};

int main()
{
    // creating the object in the stack memory
    Entity entity("HollowMike");
    std::cout << entity.GetName() << std::endl;

    // creating the object in the heap memory
    Entity* entity2 = new Entity("Heap Object!");
    std::cout << (*entity2).GetName() << std::endl;
    delete entity2;
}