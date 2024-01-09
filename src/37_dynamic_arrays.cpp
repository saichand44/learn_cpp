#include <iostream>
#include <vector>    // include library to use the std::vector

// Dynamic arrays are bacially used when we are not sure of the size of the entires
// and they are also contiguous memory like arrays. Here the dynamic arrays have
// some default size and when it gets filled up, an entirely new block of continguous
// memory (like double the previous size) is created and then the old data is
// copied to the new memory block and we can add additional entiries in the new size.

// This is different from linked list where the memory is not continguous and is more
// efficient in terms of memory usage (though linked lists themselves have an overhead
// memory for pointers to nodes).

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
};

// overload the "<<" operator to print the elements of vertex struct
std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    std::vector<Vertex> vertices;
    // we can use primitive data type as well depeding on use case
    // std::vector<int> integers;   | std::vector<DATA_TYPE> NAME;

    // Here we are using the data itself rather than pointers as vector is 
    // contiguous memory, it makes sense to put the objects in a order rather than
    // their addresses. It makes it easier for accessing/modifying..etc. But we
    // when copying the objects from their original memory block to new memory 
    // block, big object might slow down the process. So judge according to use case!

    // add stuff to vector
    vertices.push_back(Vertex(1, 2, 3));
    vertices.push_back(Vertex(4, 5, 6));

    // iterate through the elements and print them
    for (int i=0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
    }

    // deleting elements in the vector
    vertices.erase(vertices.begin() + 0); // the integer number is the index of the element to delete


    // alternate way of using for loop
    // In fucntions, if we want to avoid copying of variables, use pass by reference
    for (Vertex& v : vertices) // here pass by reference to avoid copying of variables
    {
        std::cout << v << std::endl;
    }

}