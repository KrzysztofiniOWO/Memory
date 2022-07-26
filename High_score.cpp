#include "High_score.h"
#include <iostream>
#include <fstream>

void High_score::load_scores()
{
    std::fstream file;
    file.open("scores.txt", std::ios::in);

    int score;

    for (int i = 0; i < 10; i++)
    {
        file >> score;
        best_scores[i] = score;
    }

    file.close();
}

void High_score::sort_scores()
{
    for (int i = 10; i>0; i--)
    {
        if( get_score(i) > get_score(i-1) )
        {
            int holder = get_score(i);
            set_score(i, get_score(i-1));
            set_score((i-1), holder);
        }
    }
}

void High_score::save_scores()
{
    std::fstream file;
    file.open("scores.txt", std::ios::out);

    for(int i = 0; i < 10; i++)
    {
        file << get_score(i) << std::endl;
    }

    file.close();
}

int High_score::get_score(int index)
{
    return best_scores[index];
}

void High_score::set_score(int index, int number)
{
    best_scores[index] = number;
}

void High_score::print_scores()
{
    for(int i = 0; i < 10; i++)
    {
        std::cout << "Score [" << (i+1) << "] is " << get_score(i) << std::endl;
    }
}
