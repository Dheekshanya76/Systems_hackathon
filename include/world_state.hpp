#ifndef WORLD_STATE_HPP
#define WORLD_STATE_HPP

#include <vector>

#include "player.hpp"
#include "command.hpp"

struct WorldState
{
    std::vector<Player> players;
};

void execute(const Command &cmd, WorldState &world);

#endif