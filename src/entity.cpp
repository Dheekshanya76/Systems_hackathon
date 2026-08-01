#include "../include/entity.hpp"

#include <cstring>


void set_player(
    PlayerRecord &record,
    uint32_t id,
    const std::string &username,
    const std::string &email
)
{
    record.id = id;


    // Clear fixed-size fields
    std::memset(
        record.username,
        0,
        sizeof(record.username)
    );

    std::memset(
        record.email,
        0,
        sizeof(record.email)
    );


    // Copy strings into fixed-size buffers

    std::memcpy(
        record.username,
        username.c_str(),
        username.size()
    );


    std::memcpy(
        record.email,
        email.c_str(),
        email.size()
    );
}