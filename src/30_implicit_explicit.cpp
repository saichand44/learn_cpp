#include <iostream>
#include <string.h>

// implicit and explicit conversions are used for type casting.
// imlicit typecasting means the compiler is allowed to automatically change
// the type of the variable. This is allowed only ONE time
// explicit typecasting means we specify (in classes) the constructor that the 
// compiler is not allowed to change the variable type

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name)
        : m_Name(name), m_Age(-1)
    {
    }

    Entity(int age)
        : m_Name("Unknown"), m_Age(age)
    {
    }

};

class Entity2
{
private:
    std::string m_Name;
    int m_Age;
public:
    // Here "explicit" keyword is used before constructors to prevent the compiler
    // to automatically convert the variable type using implicit conversion
    explicit Entity2(const std::string& name)
        : m_Name(name), m_Age(-1)
    {
    }

    explicit Entity2(int age)
        : m_Name("Unknown"), m_Age(age)
    {
    }

};

int main()
{
    Entity a("HollowMike");
    Entity b(22);

    // Altenrate syntax for writing that includes implicit type casting by compiler

    // Entity e = "HollowMike"; //--> This is not allowed for implicit conversion
    // as the compiler needs to convert the const char* to string and then to Entity
    // So it is effectively two steps and it is not allowed for implicit conversion!

    // Instead use this.. In this case the compiler needs to do only once the 
    // type casting and hence implicit conversion
    Entity c = std::string("HollowMike"); // or Entity("HollowMike");

    Entity d = 22;
}