#include <iostream>
#include <string.h>

struct Vector2
{
public:
    int x, y;

    Vector2(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size+1]; // 1 to accomodate the null terminator "\0"

        // we can use a for loop to copy the individual charaters one by one to the
        // m_Buffer but an easier way is to use memcpy!!
        memcpy(m_Buffer, string, m_Size);
        // manually adding the null terminator. Note since m_Buffer is "char"
        // datatype, when we assign "0", we are referring to the ascii reference
        // "0" which when decoded we get "\0"
        m_Buffer[m_Size] = 0;
    }

    String(const String& other)
        :m_Size(other.m_Size)
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size+1);
    }

    // Destructor (if we use smart pointer, we can avoid this step)
    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    int a = 5;
    int b = a;
    // Here both a and b have independent memory addresses and we can change b
    // without changing the value of a
    b = 10;

    Vector2 c = {2, 4};
    Vector2 d = c;
    // Here as well we can change the contents of the vector2 variable "d" without
    // affecting the contents of "c".
    d.x = 10;
    d.y = 12;

    // In all the above cases, we simply just copy the exiting values to a new
    // memory location and since the memory addresses are not shared, we can easily
    // modify the contents at the new memory address

    // TIME TO INCREASE THE STAKES XD !
    Vector2* e = new Vector2(10, 13);
    Vector2* f = e;
    f->x = 17;
    std::cout << e->x << ", " << e->y << std::endl;
    std::cout << f->x << ", " << f->y << std::endl;
    // In this case, we memory address of "e" is shared by the new variable "f"
    // and they are not independent anymore. If we change the contents of "f", it will
    // change the contents of "e" as f is poitning to address of e.
    // Ex: f->x = 17;

    String string = "HollowMike";
    String secondString = string;
    secondString[1] = 'i';

    // Below line doesn't work since it is not defined in << operator => Need overloading
    // std::cout << string << std::endl;
    std::cout << string << std::endl;
    std::cout << secondString << std::endl;

    // Here when the scope of the current curly braces is finished, we start
    // deleting the string objects, but since both string and secondString refer
    // to the same address, we try to delete a second time the same memory which was
    // already deleted before!! 
    // We get the following error: free(): double free detected in tcache 2

    // To avoid this, we use a copy constructor
}   