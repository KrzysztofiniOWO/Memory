#include "Memory_Viewer.h"
#include <iostream>

Memory_Viewer::Memory_Viewer(Memory_Commands &memory_commands):
memory_commands(memory_commands)
{}

void Memory_Viewer::show_board() const
{
    for(int i = 0; i < memory_commands.get_width(); i++)
    {
        std::cout << std::endl;

        for(int j = 0; j < memory_commands.get_height(); j++)
        {
            std::cout << "[";

            if(memory_commands.is_field_revealed(i, j))
            {
                std::cout << memory_commands.get_field_value(i, j);
            }else
            {
                memory_commands.show_field_as_hidden();
            }
            std::cout << "]";
        }
    }

    std::cout << std::endl << std::endl;
}

void Memory_Viewer::show_points() const
{
    std::cout << "******************************" << std::endl;
    std::cout << "You currently have " << memory_commands.return_points() << " points." << std::endl;
    std::cout << "******************************" << std::endl << std::endl;
}
