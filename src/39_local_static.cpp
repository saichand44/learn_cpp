#include <iostream>

// "static" keyword fucntionalities --> lifetime and scope

// 'static' can be used in functions itself to declare the variable only once
// and when the function is called next time, the static variable is not
// initialized again but istead it uses the value that it was previously carrying
// in the last call. 

void Fucntion()
{
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

class Singleton
{
public:
    static Singleton& Get()
    {   
        // since we are defining the static variable for the instance, we are
        // only creating for the very first time and then reusing it as needed
        // for all the subsequent calls. 
        // Here since we are using "&" in the fucntion it is important to extend 
        // the lifetime of the varible using the static keyword. Otherwise, the
        // "instance" variable gets destroyed as soon as we finish the Get() function
        static Singleton instance;
        return instance;
    }

    void Hello()
    {
        std::cout << "Hello World!" << std::endl;
    }
};

int main()
{
    Singleton::Get().Hello();
}