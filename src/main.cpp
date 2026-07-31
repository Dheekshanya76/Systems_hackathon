#include <iostream>
#include <string>

void help()
{
    std::cout << ".quit       Shut down the world engine\n";
    std::cout << ".help       Show this message\n";
    std::cout << ".version    Show engine version\n";
    std::cout << ".status     Show world status\n";
}

void version()
{
    std::cout << "Chronicle v0.1 - Ironhold World Engine\n";
}

void status()
{
    std::cout << "World: offline\n";
}

void worldCommand(const std::string &input)
{
    std::cout << "[World command queued: " << input << "]\n";
}

void unknownCommand()
{
    std::cout << "Unknown command. Try .help\n";
}

bool handleMeta(const std::string &input)
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
    std::string input;

    while (true)
    {
        std::cout << "ironhold> ";

        if (!std::getline(std::cin, input))
            break;

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