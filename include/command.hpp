#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

enum class CommandType
{
    SPAWN_PLAYER,
    LIST_PLAYERS,
    INVALID
};

struct Command
{
    CommandType type;

    unsigned int id;
    std::string username;
    std::string email;

    std::string error;
};

Command parseCommand(const std::string &input);

#endif