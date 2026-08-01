#include <iostream>
#include <string>

#include "../include/world_state.hpp"
#include "../include/command.hpp"

Command parseCommand(const std::string &input);
void execute(const Command &cmd, WorldState &world);

void help()
{
    std::cout << ".quit       Shut down the world engine\n";
    std::cout << ".help       Show this message\n";
    std::cout << ".version    Show engine version\n";
    std::cout << ".status     Show world status\n";
}

void version()
{
    std::cout << "Chronicle v0.2 - Ironhold World Engine\n";
}

void status()
{
    std::cout << "World: online\n";
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
        std::cout << "Unknown command. Try .help\n";
    }

    return true;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    WorldState world;
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
            Command cmd = parseCommand(input);
            execute(cmd, world);
        }
    }

    return 0;
}