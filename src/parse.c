/*
** EPITECH PROJECT, 2022
** parse.c
** File description:
** parse functions
*/

#include "my_sokoban.h"

void modify_pos(struct moveables *objects, char c, int i)
{
    if (c == 'l') {
        objects->player_x += 1;
        objects->boxes[i].x += 1;
    }
    if (c == 'r') {
        objects->player_x -= 1;
        objects->boxes[i].x -= 1;
    }
    if (c == 'u') {
        objects->player_y += 1;
        objects->boxes[i].y += 1;
    }
    if (c == 'd') {
        objects->player_y -= 1;
        objects->boxes[i].y -= 1;
    }
}

void parse_boxes(struct moveables *objects, char c, int i)
{
    for (int j = i + 1; j < objects->nb_box; ++j) {
        if (is_colliding(objects->boxes[i], objects->boxes[j]) == 1) {
            modify_pos(objects, c, i);
            return;
        }
    }
}

void print_all(struct moveables *objects, char **map)
{
    print_map(map);
    print_objects(objects);
}
