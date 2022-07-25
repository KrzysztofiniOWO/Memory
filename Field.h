#pragma once
#include <string>
#include <vector>


class Field {

private:

    std::vector<char> values = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char value = 'X';
    bool revealed = false;

public:

    //Return char value of our field
    char get_value() const;

    //Hidden value for our field
    char get_hidden_value() const;

    //Get the state of our field (is revealed or not)
    bool get_revealed() const;

    //Reveals our field if hidden and hides it if revealed
    void change_reveal_of_field();

    //Take values from our list while generating board
    char next_value(int number);

    //Set value of our field with a given char
    void set_value(char val);

};
