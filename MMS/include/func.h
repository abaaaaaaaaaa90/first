#ifndef FUNC_H
#define FUNC_H

#include "matrix.h"
#include <vector>

using namespace std;

int searchName(string);
void add(vector<string> command);
int is_diagonal(string);
int is_upper_triangular(string);
int is_lower_triangular(string);
void is_triangular(string);
void is_identity(string);
int is_normal_symmetric(string);
int is_skew_symmetric(string);
void is_symmetric(string);
void inverse(string, string = "");
void show(string);
void remove(string);
void change(string, int, int, float);

#endif