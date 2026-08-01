#include <algorithm>
#include <iostream>

#include "../include/world_state.hpp"
#include "../include/command.hpp"

void execute(const Command &cmd, WorldState &world)
{
    if (cmd.type == CommandType::INVALID)
    {
        std::cout << "Error: " << cmd.error << std::endl;
        return;
    }

    if (cmd.type == CommandType::SPAWN_PLAYER)
    {
        for (const auto &player : world.players)
        {
            if (player.id == cmd.id)
            {
                std::cout << "Error: Entity already exists." << std::endl;
                return;
            }
        }

        Player p;

        p.id = cmd.id;
        p.username = cmd.username;
        p.email = cmd.email;

        world.players.push_back(p);

        std::cout << "Spawned." << std::endl;
    }

    else if (cmd.type == CommandType::LIST_PLAYERS)
    {
        std::sort(world.players.begin(),
                  world.players.end(),
                  [](const Player &a, const Player &b)
                  {
                      return a.id < b.id;
                  });

        for (const auto &player : world.players)
        {
            std::cout << "[" << player.id << "] "
                      << player.username
                      << " <"
                      << player.email
                      << ">"
                      << std::endl;
        }

        std::cout << world.players.size()
                  << " entities."
                  << std::endl;
    }
}