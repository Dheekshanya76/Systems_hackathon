#include "../include/command.hpp"

#include <sstream>

Command parseCommand(const std::string &input)
{
    Command cmd;
    std::stringstream ss(input);

    std::string word;

    ss >> word;

    if (word == "SPAWN")
    {
        ss >> word;

        if (word != "PLAYER")
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "Syntax Error";
            return cmd;
        }

        int id;

        if (!(ss >> id))
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "Syntax Error";
            return cmd;
        }

        if (id <= 0)
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "ID must be positive.";
            return cmd;
        }

        cmd.id = id;

        if (!(ss >> cmd.username >> cmd.email))
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "Syntax Error";
            return cmd;
        }

        if (cmd.username.length() > 32)
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "username too long (max 32 chars).";
            return cmd;
        }

        if (cmd.email.length() > 255)
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "email too long (max 255 chars).";
            return cmd;
        }

        std::string extra;

        if (ss >> extra)
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "Syntax Error";
            return cmd;
        }

        cmd.type = CommandType::SPAWN_PLAYER;
    }

    else if (word == "LIST")
    {
        ss >> word;

        if (word != "PLAYERS")
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "Syntax Error";
            return cmd;
        }

        std::string extra;

        if (ss >> extra)
        {
            cmd.type = CommandType::INVALID;
            cmd.error = "Syntax Error";
            return cmd;
        }

        cmd.type = CommandType::LIST_PLAYERS;
    }

    else
    {
        cmd.type = CommandType::INVALID;
        cmd.error = "Syntax Error";
    }

    return cmd;
}