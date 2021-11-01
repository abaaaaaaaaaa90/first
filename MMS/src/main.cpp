#include "whatCommand.h"
#include "matrix.h"
#include "func.h"

void showMenu(string e)
{
    cerr << e << endl
         << "Command list :" << endl
         << "add" << endl
         << "is_diagonal" << endl
         << "is_upper_triangular" << endl
         << "is_lower_triangular" << endl
         << "is_triangular" << endl
         << "is_identity" << endl
         << "is_normal_symmetric" << endl
         << "is_skew_symmetric" << endl
         << "is_symmetric" << endl
         << "inverse" << endl
         << "show" << endl
         << "remove" << endl
         << "change" << endl
         << "exit" << endl;
}

int main() // Start app
{
    string command;
    vector<string> getCommand; // token command
    while (1)
    {
        cout << "> ";          // command line :)
        getline(cin, command); // read command in console
        if (command == "")     // empty input
            continue;
        if (command == "exit")
            break;
        try
        {
            getCommand = whatCommand(command);
        }
        catch (const std::exception &e)
        {
            showMenu(e.what());
            continue;
        }
        if (getCommand[0] == "add")
            add(getCommand);
        else if (getCommand[0] == "is_diagonal")
        {
            int temp = is_diagonal(getCommand[1]);
            if (temp == 1)
                cout << "Yes" << endl;
            else if (temp == 0)
                cout << "No" << endl;
        }
        else if (getCommand[0] == "is_upper_triangular")
        {
            int temp = is_upper_triangular(getCommand[1]);
            if (temp == 1)
                cout << "Yes" << endl;
            else if (temp == 0)
                cout << "No" << endl;
        }
        else if (getCommand[0] == "is_lower_triangular")
        {
            int temp = is_lower_triangular(getCommand[1]);
            if (temp == 1)
                cout << "Yes" << endl;
            else if (temp == 0)
                cout << "No" << endl;
        }
        else if (getCommand[0] == "is_triangular")
            is_triangular(getCommand[1]);
        else if (getCommand[0] == "is_identity")
            is_identity(getCommand[1]);
        else if (getCommand[0] == "is_normal_symmetric")
        {
            int temp = is_normal_symmetric(getCommand[1]);
            if (temp == 1)
                cout << "Yes" << endl;
            else if (temp == 0)
                cout << "No" << endl;
        }
        else if (getCommand[0] == "is_skew_symmetric")
        {
            int temp = is_skew_symmetric(getCommand[1]);
            if (temp == 1)
                cout << "Yes" << endl;
            else if (temp == 0)
                cout << "No" << endl;
        }
        else if (getCommand[0] == "is_symmetric")
            is_symmetric(getCommand[1]);
        else if (getCommand[0] == "inverse")
            if (getCommand.size() == 2)
                inverse(getCommand[1]);
            else
                inverse(getCommand[1], getCommand[2]);
        else if (getCommand[0] == "show")
            show(getCommand[1]);
        else if (getCommand[0] == "remove")
            remove(getCommand[1]);
        else if (getCommand[0] == "change")
            change(getCommand[1], stoi(getCommand[2]), stoi(getCommand[3]), stof(getCommand[4]));
        else
        {
            showMenu(getCommand[0]);
            continue;
        }
        cin.ignore(); // for Segmentation fault (core dumped)
        cout << "Please press enter...";
        getchar();
        system("clear || cls"); // clear screen page
    }
    return 0;
}