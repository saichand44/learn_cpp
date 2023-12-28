#include <iostream>
#include <string.h>

// There are lot of operators used in C++. &, <<, * etc are all operators including
// mathematical operators

// operator overloading --> this is basically a functionality to act as an alias
// for a certain action. Don't over use this!

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y)
    {

    }

    Vector2 Add(const Vector2& other) const
    {
        return Vector2(+other.x, y+other.y);
    }

    // Using + as an alias / overloaded operator to do certain specific operations
    Vector2 operator+(const Vector2& other) const
    {
        return Add(other);
    }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << ", " << other.y;
    return stream;
}


int main()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);

    // Vector2 result = position + speed??? This doesn't make sense as '+' doesn't
    // do the exact job of addition in this case. Hence we need an alias that
    // uses '+' but does the vectorized addition

    Vector2 result = position.Add(speed); // This can be replaced with an overloaded operator
    Vector2 result2 = position + speed;

    std::cout << result.x << "," << result.y << std::endl;
    std::cout << result2.x << "," << result2.y << std::endl;

    // std::cout << result << std::endl --> This will not print the result as the
    // the Vector2 is not recognised by the "<<" operator in std:cout. So we need
    // to define some custom function to print. Basically overload the "<<" operator
    std::cout << result2 << std::endl;
}