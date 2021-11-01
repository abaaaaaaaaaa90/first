#include "func.h"

vector<matrix *> mt;

int searchName(string name)
{
    for (int i = 0; i < mt.size(); i++)
        if (mt[i]->name == name)
            return i; // return index in vector
    return -1;
}

void add(vector<string> command)
{
    if (searchName(command[2]) != -1)
    {
        cerr << "matrix name is exist!" << endl;
        return;
    }
    try
    {
        if (command.size() == 4)
        {
            mt.push_back(new matrix(command[2], stoi(command[3]), stoi(command[3]))); // add matrix to vector
            for (int i = 0; i < stoi(command[3]); i++)
                for (int j = 0; j < stoi(command[3]); j++) // get matrix elements...
                {
                    cout << "Enter element " << i + 1 << ' ' << j + 1 << " : ";
                    cin >> mt.back()->table[i][j];
                }
        }
        else if (command.size() == 5 && command[4][0] != '[')
        {
            mt.push_back(new matrix(command[2], stoi(command[3]), stoi(command[4]))); // add matrix to vector
            for (int i = 0; i < stoi(command[3]); i++)
                for (int j = 0; j < stoi(command[4]); j++) // get matrix elements...
                {
                    cout << "Enter element " << i + 1 << ' ' << j + 1 << " : ";
                    cin >> mt.back()->table[i][j];
                }
        }
        else if (command.size() == 6)
        {
            mt.push_back(new matrix(command[2], stoi(command[3]), stoi(command[4]))); // add matrix to vector
            int arr[mt.back()->row * mt.back()->col];                                 // for token 1,2,3...
            command[5].erase(0, 1);                                                   // remove [
            command[5].erase(command[5].size() - 1, 1);                               // remove ]
            string temp = "";
            int k = 0;                                  // arr index
            for (int i = 0; i < command[5].size(); i++) // token matrix elements...
            {
                if (command[5][i] == ',')
                {
                    arr[k++] = stoi(temp);
                    temp = "";
                    continue;
                }
                temp += command[5][i];
            }
            if (temp != "")
                arr[k++] = stoi(temp);
            k = 0;
            for (int i = 0; i < mt.back()->row; i++)
                for (int j = 0; j < mt.back()->col; j++)
                    mt.back()->table[i][j] = arr[k++]; // add matrix elements...
        }
        else
        {
            mt.push_back(new matrix(command[2], stoi(command[3]), stoi(command[3]))); // add matrix to vector
            int arr[mt.back()->row * mt.back()->col];                                 // for token 1,2,3...
            command[4].erase(0, 1);                                                   // remove [
            command[4].erase(command[4].size() - 1, 1);                               // remove ]
            string temp = "";
            int k = 0;                                  // arr index
            for (int i = 0; i < command[4].size(); i++) // token matrix elements...
            {
                if (command[4][i] == ',')
                {
                    arr[k++] = stoi(temp);
                    temp = "";
                    continue;
                }
                temp += command[4][i];
            }
            if (temp != "")
                arr[k++] = stoi(temp);
            k = 0;
            for (int i = 0; i < mt.back()->row; i++) // add matrix elements...
                for (int j = 0; j < mt.back()->col; j++)
                    mt.back()->table[i][j] = arr[k++]; // get elements...
        }
    }
    catch (const std::exception &e)
    {
        cerr << "row or col or element matrix is not a number!" << endl;
        return;
    }
    cout << "Done." << endl;
}

int is_diagonal(string name)
{
    int i = searchName(name);
    if (1 == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return 2;
    }
    if (mt[i]->row != mt[i]->col) // The matrix is not square
        return 0;
    else
    {
        for (int j = 0; j < mt[i]->row; j++) // Start checking
            for (int k = 0; k < mt[i]->col; k++)
                if (j != k && mt[i]->table[j][k] != 0)
                    return 0; // No
        return 1;             // Yes
    }
}

int is_upper_triangular(string name)
{
    int i = searchName(name);
    if (i == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return 2;
    }
    if (mt[i]->row != mt[i]->col) // The matrix is not square
        return 0;
    else
    {
        for (int j = 0; j < mt[i]->row; j++) // Start checking
            for (int k = 0; k < mt[i]->col; k++)
                if (j <= k)
                    continue;
                else if (mt[i]->table[j][k] != 0)
                    return 0; // No
        return 1;             // Yes
    }
}

int is_lower_triangular(string name)
{
    int i = searchName(name);
    if (i == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return 2;
    }
    if (mt[i]->row != mt[i]->col) // The matrix is not square
        return 0;
    else
    {
        for (int j = 0; j < mt[i]->row; j++) // Start checking
            for (int k = 0; k < mt[i]->col; k++)
                if (j >= k)
                    continue;
                else if (mt[i]->table[j][k] != 0)
                    return 0; // No
        return 1;             // Yes
    }
}

void is_triangular(string name)
{
    int u = 0, l = 0;
    if (searchName(name) == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return;
    }
    if (is_upper_triangular(name) == 1)
        u++;
    if (is_lower_triangular(name) == 1)
        l++;
    if (u == 1 && l == 1)
        cout << "Both" << endl;
    else if (u == 1)
        cout << "is_upper_triangular" << endl;
    else if (l == 1)
        cout << "is_lower_triangular" << endl;
    else
        cout << "None." << endl;
}

void is_identity(string name)
{
    int temp = is_diagonal(name);
    if (temp == 2) // not exist
        return;
    else if (temp == 0)
    {
        cout << "No" << endl;
        return;
    }
    int i = searchName(name);
    for (int j = 0; j < mt[i]->row; j++) // check 1,1 - 2,2 - ...
        if (mt[i]->table[j][j] != 1)
        {
            cout << "No" << endl;
            return;
        }
    cout << "Yes" << endl;
}

int is_normal_symmetric(string name)
{
    int i = searchName(name);
    if (i == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return 2;
    }
    if (mt[i]->row != mt[i]->col) // The matrix is not square
        return 0;
    else
        for (int j = 0; j < mt[i]->row; j++) // Start checking
            for (int k = 0; k < mt[i]->col; k++)
                if (mt[i]->table[j][k] != mt[i]->table[k][j])
                    return 0; // No
    return 1;                 // Yes
}

int is_skew_symmetric(string name)
{
    int i = searchName(name);
    if (i == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return 2;
    }
    if (mt[i]->row != mt[i]->col) // The matrix is not square
        return 0;                 // No
    else
        for (int j = 0; j < mt[i]->row; j++) // Start checking
            for (int k = 0; k < mt[i]->col; k++)
                if (mt[i]->table[j][k] != -mt[i]->table[k][j])
                    return 0; // No
    return 1;                 // Yes
}

void is_symmetric(string name)
{
    int n = 0, s = 0; // normal & skew
    if (searchName(name) == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return;
    }
    if (is_normal_symmetric(name) == 1)
        n++;
    if (is_skew_symmetric(name) == 1)
        s++;
    if (n == 1 && s == 1)
        cout << "Both" << endl;
    else if (n == 1)
        cout << "is_normal_symmetric" << endl;
    else if (s == 1)
        cout << "is_skew_symmetric" << endl;
    else
        cout << "None." << endl;
}

void inverse(string n1, string n2)
{
    if (searchName(n2) != -1)
    {
        cerr << "matrix name for new save is exist!" << endl;
        return;
    }
    int i = searchName(n1);
    if (i == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return;
    }
    if (mt[i]->row != mt[i]->col)
    {
        cout << "This is not a square matrix!" << endl;
        return;
    }
    matrix *temp(mt[i]);
    for (int j = 0; j < temp->row; j++) // Start checking
        for (int k = 0; k < temp->col; k++)
            temp->table[j][k] *= -1;
    if (n2 == "") // inverse mt1
        mt[i] = temp;
    else // inverse mt1 mt2
    {
        temp->name = n2;
        mt.push_back(new matrix(*temp));
    }
    cout << "Done." << endl;
}

void show(string name)
{
    int i = searchName(name);
    if (i == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return;
    }
    for (int j = 0; j < mt[i]->row; j++)
    {
        for (int k = 0; k < mt[i]->col; k++)
            cout << mt[i]->table[j][k] << ' ';
        cout << endl;
    }
}

void remove(string name)
{
    int i = searchName(name);
    if (i == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return;
    }
    mt.erase(mt.begin() + i);
    cout << "Done." << endl;
}

void change(string name, int r, int c, float new_element) // r = row & c = col
{
    int i = searchName(name);
    if (i == -1)
    {
        cerr << "matrix is not exist!" << endl;
        return;
    }
    mt[i]->table[r - 1][c - 1] = new_element;
    cout << "Done." << endl;
}