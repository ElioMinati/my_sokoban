/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** initialization functions
*/

#include <stdlib.h>
#include "my_sokoban.h"

static void check_line(struct moveables *objects, char **map, int i, int *count)
{

    for (int j = 0; map[i][j] != '\0'; ++j) {
        if (map[i][j] == 'P') {
            objects->player_x = j;
            objects->player_y = i;
            map[i][j] = ' ';
        }
        if (map[i][j] == 'X') {
            objects->boxes[count[0]].x = j;
            objects->boxes[count[0]].y = i;
            objects->boxes[count[0]].is_in_corner = 0;
            map[i][j] = ' ';
            ++count[0];
        }
        if (map[i][j] == 'O') {
            objects->holes[count[1]].x = j;
            objects->holes[count[1]].y = i;
            ++count[1];
        }
    }
}

void get_mv_objects(struct moveables *objects, char **map)
{
    int count[2] = {0, 0};

    for (int i = 0; map[i] != NULL; ++i) {
        check_line(objects, map, i, count);
    }
}

void init_moveables(struct moveables *objects, char **map)
{
    objects->boxes = malloc(get_nb_boxes(map) * sizeof(struct object));
    objects->holes = malloc(get_nb_holes(map) * sizeof(struct object));
    objects->nb_box = get_nb_boxes(map);
    objects->nb_holes = get_nb_holes(map);
    get_mv_objects(objects, map);
}
