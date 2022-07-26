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

void Memory_Control::get_coords()
{
    int cord_1[2], cord_2[2];
    std::cout << "Enter coordinate x of first field: " << std::endl;
    std::cin >> cord_1[0];
    std::cout << "Enter coordinate y of first field: " << std::endl;
    std::cin >> cord_1[1];
    std::cout << "Enter coordinate x of second field: " << std::endl;
    std::cin >> cord_2[0];
    std::cout << "Enter coordinate y of second field: " << std::endl;
    std::cin >> cord_2[1];

    memory_viewer.show_board();

    fields += memory_commands.match_fields(cord_1[0], cord_1[1], cord_2[0], cord_2[1]);
}

void Memory_Control::play_memory()
{
    memory_commands.set_width_height();
    count_fields();
    memory_commands.generate_board();

    while(fields > 0)
    {

        memory_viewer.show_board();
        get_coords();
        memory_commands.gravity_mode();
        memory_viewer.show_points();

    }

    std::cout << "Congratulations you won. Your score is " << memory_commands.return_points() << std::endl;
    std::cout << "Now let's check our scoreboard" << std::endl;

    high_score.load_scores();
    high_score.set_score(10, memory_commands.return_points());
    high_score.sort_scores();
    high_score.print_scores();
    high_score.save_scores();

}
