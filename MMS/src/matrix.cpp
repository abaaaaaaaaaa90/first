#include "matrix.h"

matrix::matrix(std::string n, int r, int c) // name, row, col
{
    name = n;
    row = r;
    col = c;
    table = new float *[row]; // 2d dynamic array
    for (int i = 0; i < row; i++)
        table[i] = new float[col];
}

matrix::~matrix()
{
    for (int i = 0; i < row; ++i) // delete 2d dynamic array
        delete[] table[i];
    delete[] table;
}