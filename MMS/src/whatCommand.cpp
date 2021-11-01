#include "whatCommand.h"

vector<string> whatCommand(string command)
{
    vector<string> token; // tokenize command
    string temp = "";
    for (int i = 0; i < command.size(); i++)
    {
        if (command[i] == ' ')
        {
            token.push_back(temp);
            temp = "";
            continue;
        }
        temp += command[i];
    }
    if (temp != "")
        token.push_back(temp);
    if (token.size() > 6)
        throw invalid_argument("Command is not valid : Maximum command size = 6");
    if (token.size() < 2)
        throw invalid_argument("Command is not valid : Minumum command size = 2");
    return token;
}