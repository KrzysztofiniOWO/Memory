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
    int points = 0;
    int modifier = 1;
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

    //Set field value to inserted char
    void set_field_value(int width, int height, char val);

    //Change state of our cell (Is revealed or not)
    void change_reveal_of_field(int width, int height);

    //In gravity mode correctly guessed cells fall down
    virtual void gravity_mode(){};

    //Add points after guessing cards correctly
    void add_points(int amount);

    //Return amount of points in current game
    int return_points();

    //If player guess correctly multiply current modifier by 2
    void increase_modifier();

    //Return value of our modifier
    int return_modifier();

    //Reset modifier to 1 after wrong guess
    void reset_modifier();



};

