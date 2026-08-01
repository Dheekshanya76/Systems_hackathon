#ifndef PAGER_HPP
#define PAGER_HPP

#include <cstdint>
#include <fstream>
#include <array>

constexpr uint32_t PAGE_SIZE = 4096;
constexpr uint32_t ENTITIES_PER_PAGE = 14;
constexpr uint32_t MAX_PAGES = 100;
constexpr uint32_t MAX_ENTITIES = 1400;


class Pager
{
private:

    std::fstream file;

    std::array<std::array<char,PAGE_SIZE>,MAX_PAGES> pages;

    std::array<bool,MAX_PAGES> loaded;
    std::array<bool,MAX_PAGES> dirty;

    std::string filename;


public:

    Pager(const std::string &filename);

    char *get_page(uint32_t page);

    void mark_dirty(uint32_t page);

    void close();

};


#endif