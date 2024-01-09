#include <iostream>
#include <vector>

// Dynamic arrays are bacially used when we are not sure of the size of the entires
// and they are also contiguous memory like arrays. Here the dynamic arrays have
// some default size and when it gets filled up, an entirely new block of continguous
// memory (like double the previous size) is created and then the old data is
// copied to the new memory block and we can add additional entiries in the new size.

// To optimize this, we can specify the memory before itself and then assign
// the elements. Also we can only pass the parameters to the vector object rather
// than copying the objects from int main and putting in the vector func. defintion

struct Vertex
{
public:
    float x, y, z;
public:
    // constructor
    Vertex(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // copy constructor
    Vertex(const Vertex& otherVertex)
    {
        std::cout << "Copied!" << std::endl;
    }

};

int main()
{
    std::vector<Vertex> vertices;

    // add stuff to vector
    // vertices.push_back(Vertex(1, 2, 3));
    // vertices.push_back(Vertex(4, 5, 6));
    // vertices.push_back(Vertex(7, 8, 9));

    // This is result of the lines 40-42
    // Copied! --> To copy the contents of first vertex from main and put in vector fucntion
    // Copied! --> Resize the vector for new element and copy old element to new memory block
    // Copied! --> To copy the contents of second vertex from main and put in vector fucntion
    // Copied! --> Resize the vector for third element and copy first element to new memory block
    // Copied! --> Copy second element to new memory block
    // Copied! --> To copy the contents of third vertex from main and put in vector fucntion

    // First optimization
    // declare the size of the vector upfront
    vertices.reserve(3); // 3 for 3 elements

    // to prevent copying from int main and putting it in the vector fucntion, use emplace_back
    vertices.emplace_back(1, 2, 3);    // just enough to pass the parameters!
    vertices.emplace_back(4, 5, 6);
    vertices.emplace_back(7, 8, 9);

    // We can still add more elements but it's just that the old elements have to
    // be copied to a new memory block and then new elements are added
    // vertices.emplace_back(10, 11, 12); // result in three copied => three old elements copied to new block


}