#include "../include/world_state.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

WorldState::WorldState(const std::string &file)
    : pager(file)
{
    filename = file;

    numEntities = 0;


    std::ifstream input(
        file,
        std::ios::binary
    );


    if(!input)
        return;



    while(true)
    {
        PlayerRecord record;


        input.read(
            reinterpret_cast<char*>(&record),
            sizeof(PlayerRecord)
        );


        if(!input)
            break;


        // Empty slots have id = 0
        if(record.id == 0)
            break;


        numEntities++;
    }
}


void *WorldState::entity_slot(uint32_t index)
{
    uint32_t page =
        index / ENTITIES_PER_PAGE;


    uint32_t offset =
        (index % ENTITIES_PER_PAGE)
        * ENTITY_SIZE;


    char *data =
        pager.get_page(page);


    return data + offset;
}





void execute(const Command &cmd, WorldState &world)
{

    if (cmd.type == CommandType::INVALID)
    {
        std::cout
            << "Error: "
            << cmd.error
            << std::endl;

        return;
    }



    if (cmd.type == CommandType::SPAWN_PLAYER)
    {

        // Check duplicate IDs

        for(uint32_t i = 0;
            i < world.numEntities;
            i++)
        {

            PlayerRecord *player =
                static_cast<PlayerRecord *>(
                    world.entity_slot(i)
                );


            if(player->id == cmd.id)
            {
                std::cout
                    << "Error: Entity already exists."
                    << std::endl;

                return;
            }
        }



        if(world.numEntities >= MAX_ENTITIES)
        {
            std::cout
                << "Error: World full."
                << std::endl;

            return;
        }



        PlayerRecord *record =
            static_cast<PlayerRecord *>(
                world.entity_slot(
                    world.numEntities
                )
            );



        set_player(
            *record,
            cmd.id,
            cmd.username,
            cmd.email
        );



        uint32_t page =
            world.numEntities /
            ENTITIES_PER_PAGE;


        world.pager.mark_dirty(page);



        world.numEntities++;



        std::cout
            << "Spawned."
            << std::endl;

    }





    else if(cmd.type == CommandType::LIST_PLAYERS)
    {

        std::vector<PlayerRecord*> players;



        for(uint32_t i = 0;
            i < world.numEntities;
            i++)
        {
            players.push_back(
                static_cast<PlayerRecord*>(
                    world.entity_slot(i)
                )
            );
        }



        std::sort(
            players.begin(),
            players.end(),
            [](PlayerRecord *a,
               PlayerRecord *b)
            {
                return a->id < b->id;
            }
        );



        for(auto player : players)
        {
            std::cout
                << "["
                << player->id
                << "] "
                << player->username
                << " <"
                << player->email
                << ">"
                << std::endl;
        }



        std::cout
            << world.numEntities
            << " entities."
            << std::endl;
    }
}