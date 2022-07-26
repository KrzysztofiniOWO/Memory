#include "Gravity_memory.h"
#include <iostream>

Gravity_memory::Gravity_memory(Field &field, Game_mode game_mode):
        Memory_Commands(field, game_mode)
{
}

void Gravity_memory::gravity_mode()
{
    int times = get_width();

    while (times > 0)
    {
        for (int i = 0; i < get_width(); i++)
        {
            for (int j = 0; j < get_height(); j++)
            {
                if(is_field_revealed(i, j))
                {
                    if((i + 1 <= get_width()-1) && (!is_field_revealed(i+1, j)))
                    {
                        char value_holder = get_field_value(i, j);
                        set_field_value(i, j, get_field_value(i+1, j ));
                        set_field_value(i+1, j, value_holder);

                        change_reveal_of_field(i, j);
                        change_reveal_of_field(i+1, j);

                    }
                }
            }
        }

        times--;
    }
}