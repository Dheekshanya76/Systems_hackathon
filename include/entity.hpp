#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstdint>
#include <string>


#pragma pack(push,1)

struct PlayerRecord
{
    uint32_t id;
    char username[32];
    char email[255];
};

#pragma pack(pop)


// Must be exactly 291 bytes
constexpr uint32_t ENTITY_SIZE = sizeof(PlayerRecord);


void set_player(
    PlayerRecord &record,
    uint32_t id,
    const std::string &username,
    const std::string &email
);


#endif