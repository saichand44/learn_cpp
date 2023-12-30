#include <iostream>

// "->" is used instead of the derefence operator (*)
// We can also overload the "->" operator

class Entity
{
public:
    int x;
public:
    void Print() const
    {
        std::cout << "Hello!" << std::endl;
    }
    void Print()
    {
        std::cout << "Hello!" << std::endl;
    }
};

class ScopedPtr
{
private:
    Entity* m_Obj;
public:
    // Constructor
    ScopedPtr(Entity* ptr)
        : m_Obj(ptr)
    { 
    }
    //Destructor
    ~ScopedPtr()
    {
        delete m_Obj;
    }

    // overload the "->" to access the m_Obj as currenly it cannot be accessed
    // from outside the scope of this class
    Entity* operator->()
    {
        return m_Obj;
    }

    const Entity* operator->() const
    {
        return m_Obj;
    }
};

int main()
{
    ScopedPtr entity = new Entity();
    entity->Print();     // overloaded operator to access the contents of entity class

    const ScopedPtr entity1 = new Entity();
    entity1->Print();     // overloaded operator to access the contents of entity class


}