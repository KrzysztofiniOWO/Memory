#include "Memory_Control.h"
#include <iostream>

Memory_Control::Memory_Control(Memory_Commands &memory_commands, Memory_Viewer &memory_viewer, High_score &high_score):
memory_commands(memory_commands),
memory_viewer(memory_viewer),
high_score(high_score)
{}

void Memory_Control::count_fields()
{
    fields = memory_commands.get_width() * memory_commands.get_height();
}

void Memory_Control::change_fields(int number)
{
    fields += number;
}

void Memory_Control::play_memory()
{
    memory_commands.set_width_height();
    count_fields();
    memory_commands.generate_board();

    while(fields > 0)
    {

        memory_viewer.show_board();
        change_fields(memory_commands.get_coords());
        memory_commands.gravity_mode();
        memory_viewer.show_points();

    }

    std::cout << "Congratulations you won. Your score is " << memory_commands.return_points() << std::endl << std::endl;
    std::cout << "Now let's check our scoreboard" << std::endl;

    high_score.load_scores();
    high_score.set_score(10, memory_commands.return_points());
    high_score.sort_scores();
    high_score.print_scores();
    high_score.save_scores();

}
