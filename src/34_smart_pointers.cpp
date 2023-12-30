#include <iostream>
#include <memory> // to access the smart pointers!

// smart pointers automate the process of "new" and "delete" the memory in the 
// heap memory.

// Three types:
// unique_ptr: These pointers cannot be copied or assigned to another pointer
// share_ptr: These pointers can be shared and assigned to another pointer and it
//            keeps track of the copies count
// weak_ptr: this takes the share_ptr after it copies but doesn't increase the ref count

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

    void Print()
    {

    }
};

int main()
{   
    {
        std::shared_ptr<Entity> e1;
        std::weak_ptr<Entity> e2;
        {
        // std::unique_ptr<Entity> entity(new Entity()); // unique_ptr has explicit defined, 
                                                        // so we need to ensure the datatype properly
        // This is the more preferred way of defining a unique_ptr than above
            std::unique_ptr<Entity> entity = std::make_unique<Entity>();

            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e1 = sharedEntity; // we can copy the pointer
            e2 = sharedEntity; // we copy the shared pointre but don't increase the ref count
        } // entity, sharedEntity, e2 are deleted after this scope
    } // e1 is deleted after this scope
}