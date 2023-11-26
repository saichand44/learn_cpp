#include <iostream>

struct EntityType1
{
    int x, y;

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

struct EntityType2
{   
    // using the 'static' basically decouples the variables x, y from the class
    // and it is equivalent to defining some global variables within the scope 
    // of this file. Also, they will be initialized only once when the class
    // is instantiated and as we update the vaariables, they will be overwritten.

    // Defining it like this makes it easier to make x, y available across all
    // instantitations and also it is more organized

    // similar steps follow for using 'static' for methods. 
    // NOTE: static methods cannot access non-static variables since they are 
    // essentially independent functions inside a class and need arguments passed
    // to do something. (similat to how @staticmethod in python cannot take
    // self.variables)
    
    static int x, y;

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }

    static void print2()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int EntityType2::x;      // --------> we need this if we are using the static variables
int EntityType2::y;      // --------> This is basically the namespace and its variables

int main()
{
    EntityType1 e;
    // access the variables (public) of the struct and assign the values
    e.x = 2;
    e.y = 3;

    // Here we are using an initializer to define the entities in the struct
    EntityType1 e1 = {5, 8};
    
    // print statements normal as expected
    e.print();
    e1.print();

    ///////////////////////////////////////////////////////////////////////////
    EntityType2 e2;
    // access the variables (public) of the struct and assign the values
    EntityType2::x = 2;
    EntityType2::y = 3;

    EntityType2 e3;
    EntityType2::x = 5;   // The x, y static variables are updated here
    EntityType2::y = 8;
    
    // print statements normal as expected
    e2.print();
    EntityType2::print2();      // since print2() is a static method 
    e3.print();
}