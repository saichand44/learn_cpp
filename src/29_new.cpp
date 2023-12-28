#include <iostream>
#include <string.h>

// "new" keyword is used for allocating continguous memory for variables, arrays..etc
// The memory is allocated in the "heap" memory. Since we have to search for the
// free memory first and then allocate, this process could be a bit slow than 
// assigning in the stack

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
    int* var = new int;              // 4 bytes of memory
    int* arr = new int[50];          // 50*4 = 200 bytes of memory 

    // we can also allocate memory for a class object
    // using "new" does two things: 1) allocates memory 2) call the constructor as well!!
    Entity* e = new Entity();

    // we can also theoretically use malloc() for memory allocation but it only
    // allocates the memory and doesn't call the construtor (in case of class)
    // This method is not recommended

    // malloc() -->  allocates a block of size bytes of memory, 
    //               returning a pointer to the beginning of the block
    Entity* e1 = (Entity*)malloc(sizeof(Entity)); // --> Here we need to typecast for malloc output

    // IMPORTANT to delete the allocated memory after usage
    delete var;
    delete[] arr;
    delete e1;

    // We can also use new(arr) where we can control from where the memory is allocated
    // (in this case arr). This is called placement
}