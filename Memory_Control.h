#pragma once
#include "Memory_Viewer.h"
#include "Memory_Commands.h"


class Memory_Control {

private:

    Memory_Commands& memory_commands;
    Memory_Viewer& memory_viewer;
    int fields;

public:

    Memory_Control(Memory_Commands& memory_commands, Memory_Viewer& memory_viewer);

    //Count amount of field for our game
    void count_fields();

    //Loop for our game
    void play_memory();

    //Get coordinates of fields from player to check if they are the same
    void get_coords();



};


