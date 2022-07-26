#pragma once
#include "Memory_Viewer.h"
#include "Memory_Commands.h"
#include "High_score.h"


class Memory_Control {

private:

    Memory_Commands& memory_commands;
    Memory_Viewer& memory_viewer;
    High_score& high_score;
    int fields;

public:

    Memory_Control(Memory_Commands& memory_commands, Memory_Viewer& memory_viewer, High_score& high_score);

    //Count amount of field for our game
    void count_fields();

    //Loop for our game
    void play_memory();

    //Update number of unrevealed fields if player guesses correctly
    void change_fields(int number);




};


