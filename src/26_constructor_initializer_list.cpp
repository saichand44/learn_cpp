#include <iostream>
#include <string.h>

// constructor initializer list has all the variables that have to be initialized 
// using the constructor.

// It is a recommender style of coding practise and also has performance benefits
// particularly when it comes to using class data types. For primitive data types,
// it won't make a big difference.

// Check Cherno Video for example on performance benefits

// Definition of a class using regular method of using constructors
class Entity1
{
private:
    std::string m_Name;
public:
    Entity1()
    {
        m_Name = "Unknown";
    }

    Entity1(const std::string& name)
    {
        m_Name = name;
    }

    const std::string& GetName() const
    {
        return m_Name;
    }
};

// Definition of a class using regular method of using constructors initilaizer list 
class Entity2
{
private:
    std::string m_Name;
    int m_Score;
public:
    Entity2()
    // Here the order of the varibales in imp and keep it consistent with the
    // initialization order from above
        : m_Name("Unknown"), m_Score(0)
    {
    }

    Entity2(const std::string& name, int score)
        : m_Name(name), m_Score(score)
    {
    }

    const std::string& GetName() const
    {
        return m_Name;
    }
};


int main()
{
    const Entity1 e0;
    std::cout << e0.GetName() << std::endl;

    const Entity1 e1("Mike");
    std::cout << e1.GetName() << std::endl;

    const Entity2 e3;
    std::cout << e3.GetName() << std::endl;

    const Entity2 e4("Hollow", 20);
    std::cout << e4.GetName() << std::endl;

}