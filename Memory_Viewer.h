#pragma once
#include "Memory_Commands.h"



class Memory_Viewer {

private:

    Memory_Commands& memory_commands;

public:

    Memory_Viewer(Memory_Commands& memory_commands);

    //Show player current state of board
    void show_board() const;

    //Show current amount of points
    void show_points() const;

};




