#include <iostream>
#include "Memory_Commands.h"
#include "Field.h"
#include "Memory_Viewer.h"
#include "Memory_Control.h"
#include "Gravity_memory.h"
#include <ctime>
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

std::string gravity_state(){

    std::string gravity;
    std::cout << "Do you want to play with gravity cells (guessed cells fall down on board)? [yes / no]: " << std::endl;
    std::cin >> gravity;

    return gravity;
}


std::unique_ptr<Memory_Commands> select_game_mode(std::string gravity, Field& field, Game_mode game_mode )
{
    if (gravity == "yes")
    {
        return std::make_unique<Gravity_memory>(field, game_mode);

    }else
    {
        return std::make_unique<Memory_Commands>(field, game_mode);
    }
}


int main() {

    srand( time(nullptr ) );

    Field field;

    std::unique_ptr<Memory_Commands> memory_commands = select_game_mode(gravity_state(), field, select_mode()); //<--- Czemu ta kurwa jebana nie działa do chuja pana

    //Gravity_memory memory_commands(field, select_mode());

    Memory_Viewer memory_viewer(*memory_commands);

    Memory_Control memory_control(*memory_commands, memory_viewer);

    memory_control.play_memory();

}
