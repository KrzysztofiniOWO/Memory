#pragma once
#include "Memory_Commands.h"

class Gravity_memory: public Memory_Commands
{

private:

public:

    Gravity_memory(Field& field, Game_mode game_mode);

    //In gravity mode correctly guessed cells fall down
    void gravity_mode() override;



};

