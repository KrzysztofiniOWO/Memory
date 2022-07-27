#include "Triple_memory_gravity.h"

#include <iostream>

Triple_memory_gravity::Triple_memory_gravity(Field &field, Game_mode game_mode):
        Gravity_memory(field, game_mode)
{}

void Triple_memory_gravity::set_width_height()
{
    if (static_cast<int>(game_mode) == 4)
    {
        width = 3;
        height = 3;

    }else if (static_cast<int>(game_mode) == 6)
    {
        width = 6;
        height = 6;

    }else
    {
        width = 9;
        height = 9;
    }

}

int Triple_memory_gravity::get_coords()
{
    int cord_1[2], cord_2[2], cord_3[2];
    std::cout << "Enter coordinate x of first field: " << std::endl;
    std::cin >> cord_1[0];
    std::cout << "Enter coordinate y of first field: " << std::endl;
    std::cin >> cord_1[1];

    std::cout << "Enter coordinate x of second field: " << std::endl;
    std::cin >> cord_2[0];
    std::cout << "Enter coordinate y of second field: " << std::endl;
    std::cin >> cord_2[1];

    std::cout << "Enter coordinate x of third field: " << std::endl;
    std::cin >> cord_3[0];
    std::cout << "Enter coordinate y of third field: " << std::endl;
    std::cin >> cord_3[1];

    return match_fields(cord_1[0], cord_1[1], cord_2[0], cord_2[1], cord_3[0], cord_3[1]);

}

int Triple_memory_gravity::match_fields(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3)
{
    if (((x_1 == x_2) && (y_1 == y_2)) || ((x_2 == x_3) && (y_2 == y_3)) || ((x_1 == x_3) && (y_1 == y_3)))
    {
        std::cout << "You selected same field" << std::endl;
        return 0;

    }else
    {
        if (!board[x_1][y_1].get_revealed() || !board[x_2][y_2].get_revealed() || !board[x_3][y_3].get_revealed())
        {
            board[x_1][y_1].change_reveal_of_field();
            board[x_2][y_2].change_reveal_of_field();
            board[x_3][y_3].change_reveal_of_field();

            if (get_field_value(x_1, y_1) == get_field_value(x_2, y_2) && get_field_value(x_2, y_2) == get_field_value(x_3, y_3))
            {
                std::cout << "Fields were the same and got removed from board." << std::endl;

                add_points(return_modifier());
                increase_modifier();
                std::cout << std::endl;
                return -3;

            } else
            {
                std::cout << "Fields were not the same. Try again!!!" << std::endl;
                std::cout << "Field 1 is [" << board[x_1][y_1].get_value() <<
                          "] and field 2 is [" << board[x_2][y_2].get_value() <<
                          "] and field 3 is [" << board[x_3][y_3].get_value() << "]." << std::endl;
                board[x_1][y_1].change_reveal_of_field();
                board[x_2][y_2].change_reveal_of_field();
                board[x_3][y_3].change_reveal_of_field();

                reset_modifier();
                std::cout << std::endl;
                return 0;
            }
        }else
        {
            std::cout << "One of the fields you selected is already revealed" << std::endl;
            return 0;
        }

    }

}

void Triple_memory_gravity::increase_modifier()
{
    modifier *= 3;
}