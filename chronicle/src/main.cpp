#include <iostream>
#include <string>

using namespace std;

void help()
{
    cout << ".quit       Shut down the world engine" << endl;
    cout << ".help       Show this message" << endl;
    cout << ".version    Show engine version" << endl;
    cout << ".status     Show world status" << endl;
}

void version()
{
    cout << "Chronicle v0.1 - Ironhold World Engine" << endl;
}

void status()
{
    cout << "World: offline" << endl;
}

void worldCommand(string input)
{
    cout << "[World command queued: " << input << "]" << endl;
}

void unknownCommand()
{
    cout << "Unknown command. Try .help" << endl;
}

bool handleMeta(string input)
{
    if (input == ".quit")
    {
        return false;
    }
    else if (input == ".help")
    {
        help();
    }
    else if (input == ".version")
    {
        version();
    }
    else if (input == ".status")
    {
        status();
    }
    else
    {
        unknownCommand();
    }

    return true;
}

int main()
{
    string input;

    while (true)
    {
        cout << "ironhold> ";

        if (!getline(cin, input))
            break;

        // Skip empty lines
        if (input.empty())
            continue;

        if (input[0] == '.')
        {
            if (!handleMeta(input))
                break;
        }
        else
        {
            worldCommand(input);
        }
    }

    return 0;
}