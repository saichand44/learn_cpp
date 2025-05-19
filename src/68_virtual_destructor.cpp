#include <iostream>

/*
Using a virtual destructor is important in the case of polymorphism where the
destructor of the derived class is not called. Using "virtual" in base class
forces the  C++ to look for the destructor in the derived class. 
*/

struct Base
{
    Base()
    {
        std::cout << "Base constructor\n";
    }

    // this destructor definition will cause issues during polymorphism
    // ~Base()
    // {
    //     std::cout << "Base destructor\n";
    // }

    // This destructor will handle cases where we have polymorphism and forces
    // C++ to look for the destructors in the derived classes
    virtual ~Base()
    {
        std::cout << "Base destructor\n";
    }
};

struct Derived : public Base
{
private:
    int *array_ptr_ = nullptr;

public:
    Derived()
    {   
        int *array_ptr_ = new int[10];

        std::cout << "Derived constructor\n";
    }

    ~Derived()
    {   
        // without the virutal keyword in the base class, during polymorphism, the 
        // this destructor will not get called and causes memory leaks
        delete[] array_ptr_;
        std::cout << "Derived destructor\n";
    }
};

int main()
{
    // here first the base constructor is called and base destructor.
    Base *base = new Base();
    delete base;

    std::cout << "=============================\n";
    
    // here first the base constructor is called and then the derived construtor
    // followed by the deriveed and base destructor respectively.
    Derived *derived = new Derived();
    delete derived;
    
    std::cout << "=============================\n";

    // In this case due to usage of "virtual", the constuctors and destructors
    // of both the derived and base classes are called properly.
    Base *poly = new Derived();
    delete poly; 

    /*
    FINAL OUTPUT:

    Base destructor
    =============================
    Base constructor
    Derived constructor
    Derived destructor
    Base destructor
    =============================
    Base constructor
    Derived constructor
    Derived destructor
    Base destructor
    */

    return 0;
}