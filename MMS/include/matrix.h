#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>

class matrix
{
public:
    matrix(std::string, int, int); // name, row, col
    ~matrix();
    std::string name;
    float **table;
    int row, col;
};
#endif