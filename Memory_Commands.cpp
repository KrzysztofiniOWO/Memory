#include "Memory_Commands.h"
#include <iostream>


Memory_Commands::Memory_Commands(Field& field, Game_mode game_mode):
field(field),
game_mode(game_mode)
{}

void Memory_Commands::set_width_height()
{
    width = static_cast<int>(game_mode);
    height = static_cast<int>(game_mode);
}

int Memory_Commands::get_width() const
{
    return width;
}

int Memory_Commands::get_height() const
{
    return height;
}

bool Memory_Commands::is_field_revealed(int width, int height)
{
    return board[width][height].get_revealed();
}

char Memory_Commands::get_field_value(int width, int height) const
{
    return board[width][height].get_value();
}

void Memory_Commands::show_field_as_hidden() const
{
    std::cout << field.get_hidden_value();
}

void Memory_Commands::generate_board()
{
    //Generate board
    for(int i = 0; i < width; i++)
    {
        std::vector<Field> vec;

        for(int j = 0; j < height; j++)
        {
            vec.push_back(field);
        }

        board.push_back(vec);
    }

    //Assign values to our fields
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            int counter = 0;
            while(counter != 1)
            {
                int row = rand()% get_width();
                int col = rand()% get_height();
                if (board[row][col].get_value() == 'X')
                {
                    board[row][col].set_value(board[row][col].next_value(i));
                    counter++;
                }

            }

        }
    }
}

int Memory_Commands::get_coords()
{
    int cord_1[2], cord_2[2];
    std::cout << "Enter coordinate x of first field: " << std::endl;
    std::cin >> cord_1[0];
    std::cout << "Enter coordinate y of first field: " << std::endl;
    std::cin >> cord_1[1];
    std::cout << "Enter coordinate x of second field: " << std::endl;
    std::cin >> cord_2[0];
    std::cout << "Enter coordinate y of second field: " << std::endl;
    std::cin >> cord_2[1];

    return match_fields(cord_1[0], cord_1[1], cord_2[0], cord_2[1]);

}

int Memory_Commands::match_fields(int x_1, int y_1, int x_2, int y_2)
{
    if ((x_1 == x_2) && (y_1 == y_2))
    {
        std::cout << "You selected same field two times" << std::endl;
        return 0;

    }else
    {
        if (!board[x_1][y_1].get_revealed() || !board[x_2][y_2].get_revealed())
        {
            board[x_1][y_1].change_reveal_of_field();
            board[x_2][y_2].change_reveal_of_field();

            if (get_field_value(x_1, y_1) == get_field_value(x_2, y_2))
            {
                std::cout << "Fields were the same and got removed from board." << std::endl;

                add_points(return_modifier());
                increase_modifier();
                std::cout << std::endl;
                return -2;

            } else
            {
                std::cout << "Fields were not the same. Try again!!!" << std::endl;
                std::cout << "Field 1 is [" << board[x_1][y_1].get_value() <<
                          "] and field 2 is [" << board[x_2][y_2].get_value() << "]." << std::endl;
                board[x_1][y_1].change_reveal_of_field();
                board[x_2][y_2].change_reveal_of_field();

                reset_modifier();
                std::cout << std::endl;
                return 0;
            }
        }else
        {
            std::cout << "One or both of the fields you selected is already revealed" << std::endl;
            return 0;
        }

    }

}

void Memory_Commands::set_field_value(int width, int height, char val)
{
    board[width][height].set_value(val);

}

void Memory_Commands::change_reveal_of_field(int width, int height)
{
    board[width][height].change_reveal_of_field();
}

void Memory_Commands::add_points(int amount)
{
    points += amount;
}

int Memory_Commands::return_points()
{
    return points;
}

void Memory_Commands::increase_modifier()
{
    modifier *= 2;
}

int Memory_Commands::return_modifier()
{
    return modifier;
}

void Memory_Commands::reset_modifier()
{
    modifier = 1;
}




