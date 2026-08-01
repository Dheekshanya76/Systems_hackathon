#include "../include/pager.hpp"

#include <cstring>


Pager::Pager(const std::string &name)
{
    filename = name;

    loaded.fill(false);
    dirty.fill(false);


    file.open(
        filename,
        std::ios::in |
        std::ios::out |
        std::ios::binary
    );


    // Create file if it does not exist
    if(!file)
    {
        file.clear();

        file.open(
            filename,
            std::ios::out |
            std::ios::binary
        );

        file.close();


        file.open(
            filename,
            std::ios::in |
            std::ios::out |
            std::ios::binary
        );
    }
}



char *Pager::get_page(uint32_t page)
{
    if(page >= MAX_PAGES)
        return nullptr;


    if(!loaded[page])
    {

        file.clear();


        file.seekg(
            page * PAGE_SIZE,
            std::ios::beg
        );


        file.read(
            pages[page].data(),
            PAGE_SIZE
        );


        std::streamsize bytesRead =
            file.gcount();


        // Clear EOF/fail flags after reading
        file.clear();



        // Fill unused page space with zeros
        if(bytesRead < PAGE_SIZE)
        {
            std::memset(
                pages[page].data() + bytesRead,
                0,
                PAGE_SIZE - bytesRead
            );
        }


        loaded[page] = true;
    }


    return pages[page].data();
}




void Pager::mark_dirty(uint32_t page)
{
    if(page < MAX_PAGES)
    {
        dirty[page] = true;
    }
}




void Pager::close()
{

    for(uint32_t i = 0; i < MAX_PAGES; i++)
    {

        if(!loaded[i])
            continue;


        file.clear();


        file.seekp(
            i * PAGE_SIZE,
            std::ios::beg
        );


        file.write(
            pages[i].data(),
            PAGE_SIZE
        );


        file.flush();
    }


    file.close();
}