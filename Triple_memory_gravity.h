#pragma once
#include "Memory_Commands.h"
#include "Gravity_memory.h"


class Triple_memory_gravity: public Gravity_memory{

private:

public:

    Triple_memory_gravity(Field& field, Game_mode game_mode);

    //Set width and height of our board based on game_mode (easy = 3X3, normal = 6X6, hard = 9X9)
    void set_width_height() override;

    //Get coordinates of fields from player to check if values of fields are the same
    int get_coords() override;

    //Player select two fields and game checks if their value is the same
    int match_fields(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3);

    //If player guess correctly multiply current modifier by 3
    void increase_modifier() override;

};