#ifndef SPRITES_H
#define SPRITES_H
#include <iostream>

enum direction_type {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct sprite {
    int y = 2;
    int x = 7;
    int color_pair = 0;
    int high = 1;
    int width = 2;
    std::string mask = "{}";

};

struct player {
    sprite sp;
    direction_type direction = DOWN;
};

extern player head;

#endif
