#include "Field.h"
#include <cstdlib>

char Field::get_value() const
{
    return value;
}

char Field::get_hidden_value() const
{
    return ' ';
}

char Field::next_value(int number)
{
   return values[number];
}

void Field::set_value(char val)
{
    value = val;
}

bool Field::get_revealed() const
{
    return revealed;
}

void Field::change_reveal_of_field()
{
    if (revealed)
    {
        revealed = false;

    }else
    {
        revealed = true;
    }
}

