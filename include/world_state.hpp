#ifndef WORLD_STATE_HPP
#define WORLD_STATE_HPP

#include <cstdint>
#include <string>

#include "pager.hpp"
#include "entity.hpp"
#include "command.hpp"


struct WorldState
{
    Pager pager;

    uint32_t numEntities;

    std::string filename;


    WorldState(const std::string &file);


    void *entity_slot(uint32_t index);
};


void execute(const Command &cmd, WorldState &world);


#endif