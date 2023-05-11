#include <iostream>


template<typename T>
struct MatrixElement
{
    int line_index;
    int column_index;
    T value;
};


template<typename T>
struct Matrix
{
    int lines;
    int columns;
};

int main(int argc, char* argv[]) 
{
    int x[2][2] = {
        1, 2,
        3, 4
    };


    std::cout << x[1][1] << std::endl;
}