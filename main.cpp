#include <iostream>
#include "Memory_Commands.h"
#include "Field.h"
#include "Memory_Viewer.h"
#include "Memory_Control.h"
#include "Gravity_memory.h"
#include "High_score.h"
#include "Triple_memory.h"
#include "Triple_memory_gravity.h"
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

std::string type_state(){

    std::string type;
    std::cout << "Do you want to match 2 or 3 fields each turn? [two/three]: " << std::endl;
    std::cin >> type;

    return type;

}


std::unique_ptr<Memory_Commands> select_game_mode(std::string gravity, std::string type, Field& field, Game_mode game_mode )
{
    if (gravity == "yes")
    {
        if (type == "two")
        {
            return std::make_unique<Gravity_memory>(field, game_mode);

        }else
        {
            return std::make_unique<Triple_memory_gravity>(field, game_mode);//
        }

    }else
    {
        if (type == "three")
        {
            return std::make_unique<Triple_memory>(field, game_mode);

        }else
        {
            return std::make_unique<Memory_Commands>(field, game_mode);
        }
    }
}


int main() {

    srand( time(nullptr ) );

    Field field;

    High_score high_score;

    std::unique_ptr<Memory_Commands> memory_commands = select_game_mode(gravity_state(), type_state(), field, select_mode()); //<--- Czemu ta kurwa jebana nie działa do chuja pana

    Memory_Viewer memory_viewer(*memory_commands);

    Memory_Control memory_control(*memory_commands, memory_viewer, high_score);

    memory_control.play_memory();

}
