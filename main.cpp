#include <iostream>
#include "Memory_Commands.h"
#include "Field.h"
#include "Memory_Viewer.h"
#include "Memory_Control.h"
#include <time.h>
#include <string>
#include <memory>

Game_mode select_mode()
{
    std::string game_mode;
    std::cout << "Select game_mode [easy, normal, hard]" << std::endl;
    std::cin >> game_mode;

    if(game_mode == "easy")
    {
        return Game_mode::easy;

    }else if (game_mode == "normal")
    {
        return Game_mode::normal;

    }else
    {
        return Game_mode::hard;
    }

}

/*
std::unique_ptr<Game_mode> select_game_mode(std::string mode)
{
    if (mode == "easy")
    {
        return std::make_unique<Game_mode> = easy;

    }else if (mode == "normal")
    {

    }else
    {

    }
    return make_unique<Song>(artist, title);
}
*/

int main() {

    srand( time( 0 ) );

    Field field;

    Memory_Commands memory_commands(field, select_mode());

    Memory_Viewer memory_viewer(memory_commands);

    Memory_Control memory_control(memory_commands, memory_viewer);

    memory_control.play_memory();

}
