#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>


const int WIDTH=12;
const int HEIGHT=22;

std::string tile_map[HEIGHT]=
{
    "            ",
    "            ",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "r          r",
    "rrrrrrrrrrrr",
};

std::string square[4]=
{
    "0000",
    "0110",
    "0110",
    "0000"
};

#endif // MAP_H
