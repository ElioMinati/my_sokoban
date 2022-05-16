/*
** EPITECH PROJECT, 2022
** get.c
** File description:
** functions used to get, grab stuff
*/

#include <stdlib.h>
#include "my_sokoban.h"

int add_count_hole(char c)
{
    if (c == 'O')
        return 1;
    return 0;
}

int add_count_box(char c)
{
    if (c == 'X')
        return 1;
    return 0;
}

int get_nb_boxes(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; ++i) {
        for (int j = 0; map[i][j] != '\0'; ++j)
            count += add_count_box(map[i][j]);
    }
    return count;
}

int get_nb_holes(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; ++i) {
        for (int j = 0; map[i][j] != '\0'; ++j)
            count += add_count_hole(map[i][j]);
    }
    return count;
}
