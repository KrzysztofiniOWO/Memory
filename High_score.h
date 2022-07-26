#pragma once


class High_score {

private:

        int best_scores[11];

public:

    High_score(){};

    //Load 10 best scores from a file
    void load_scores();

    //Check if the new score is higher than loaded scores. If yes place him on a list
    void sort_scores();

    //Save updated score list to a file
    void save_scores();

    //Access one certain score from our list
    int get_score(int index);

    //Set one certain score from our list
    void set_score(int index, int number);

    //Shows 10 best scores to player
    void print_scores();

};


