/*
** EPITECH PROJECT, 2022
** move_object.c
** File description:
** functions used to move objects in the map
*/

#include "my_sokoban.h"

void move_up(struct moveables *objects, char **map)
{
    int px = objects->player_x;
    int py = objects->player_y - 1;
    int bx;
    int by;

    objects->player_y -= 1;
    for (int i = 0; i < objects->nb_box; ++i) {
        bx = objects->boxes[i].x;
        by = objects->boxes[i].y;
        if (px == bx && py == by && map[by - 1][bx] != '#') {
            objects->boxes[i].y -= 1;
        } else if (px == bx && py == by) {
            objects->player_y += 1;
        }
    }
    is_box_collide(objects, 'u');
}

void move_down(struct moveables *objects, char **map)
{
    int px = objects->player_x;
    int py = objects->player_y + 1;
    int bx;
    int by;

    objects->player_y += 1;
    for (int i = 0; i < objects->nb_box; ++i) {
        bx = objects->boxes[i].x;
        by = objects->boxes[i].y;
        if (px == bx && py == by && map[by + 1][bx] != '#') {
            objects->boxes[i].y += 1;
        } else if (px == bx && py == by) {
            objects->player_y -= 1;
        }
    }
    is_box_collide(objects, 'd');
}
