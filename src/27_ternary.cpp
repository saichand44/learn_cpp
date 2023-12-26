#include <iostream>

// ternary operator is syntatic sugar for "if / else" statement

// It makes the code to look cleaner and also make it a tiny little bit faster
// Avoid using nested ternary operator as it can be difficult to understand

static int s_Level = 6;
static int s_Speed = 2;

int main()
{
    s_Speed = s_Level > 5? 10 : 5;
    std::cout << s_Speed << std::endl;

    std::string rank = s_Level > 5? "Master" : "Novice";
    std::cout << rank << std::endl;
}