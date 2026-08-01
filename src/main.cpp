#include <iostream>
#include <string>

#include "../include/world_state.hpp"
#include "../include/command.hpp"


Command parseCommand(const std::string &input);
void execute(const Command &cmd, WorldState &world);



void help()
{
    std::cout
        << ".quit       Shut down the world engine\n"
        << ".help       Show this message\n"
        << ".version    Show engine version\n"
        << ".status     Show world status\n";
}



void version()
{
    std::cout
        << "Chronicle v0.3 - Ironhold World Engine\n";
}



void status(WorldState &world)
{
    uint32_t pages =
        (world.numEntities + ENTITIES_PER_PAGE - 1)
        / ENTITIES_PER_PAGE;


    std::cout
        << "World: online — "
        << world.filename
        << " ("
        << world.numEntities
        << " entities, "
        << pages
        << " pages)"
        << std::endl;
}



bool handleMeta(
    const std::string &input,
    WorldState &world)
{

    if(input == ".quit")
    {
        return false;
    }


    else if(input == ".help")
    {
        help();
    }


    else if(input == ".version")
    {
        version();
    }


    else if(input == ".status")
    {
        status(world);
    }


    else
    {
        std::cout
            << "Unknown command. Try .help\n";
    }


    return true;
}





int main(int argc, char *argv[])
{

    if(argc < 2)
    {
        std::cout
            << "Usage: ./chronicle <world_file>\n";

        return 1;
    }



    WorldState world(argv[1]);



    std::string input;



    while(true)
    {

        std::cout
            << "ironhold> ";


        if(!std::getline(std::cin,input))
            break;



        if(input.empty())
            continue;



        if(input[0] == '.')
        {

            if(!handleMeta(input,world))
            {
                world.pager.close();
                break;
            }

        }

        else
        {

            Command cmd =
                parseCommand(input);


            execute(cmd,world);

        }

    }



    return 0;
}