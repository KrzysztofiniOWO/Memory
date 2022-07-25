#pragma once
#include "Field.h"
#include <string>
#include <vector>

enum class Game_mode { easy = 4, normal = 6, hard = 8 };

class Memory_Commands {

private:

    Field& field;
    std::vector<std::vector<Field>> board;
    int height, width;
    Game_mode game_mode;

public:

    Memory_Commands(Field& field, Game_mode game_mode);

    //Set width and height of our board based on game_mode (easy = 4X4, normal = 6X6, hard = 8X8)
    void set_width_height();

    //Get width of our board
    int get_width() const;

    //Get the height of our board
    int get_height() const;

    //Checks if our field is revealed or not
    bool is_field_revealed(int width, int height);

    //Generates board for our memory game
    void generate_board();

    //Gets value of our field
    char get_field_value(int width, int height) const;

    //Show our field with a hidden value
    void show_field_as_hidden() const;

    //Player select two fields and game checks if their value is the same
    int match_fields(int x_1, int y_1, int x_2, int y_2);

    //Reveals our field if hidden and hides it if revealed
    void change_reveal_of_field(int width, int height);



};

