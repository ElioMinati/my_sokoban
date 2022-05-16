/*
** EPITECH PROJECT, 2022
** conditions.c
** File description:
** functions used to handle specific conditions
*/

#include "my_sokoban.h"

int is_box_in_storage(struct moveables *objects, int i, int j)
{
    if (objects->holes[i].x == objects->boxes[j].x &&
    objects->holes[i].y == objects->boxes[j].y)
        return 1;
    return 0;
}

int is_box_in_corner(struct moveables *objects, char **map, int i)
{
    int x = objects->boxes[i].x;
    int y = objects->boxes[i].y;

    if (map[y - 1][x] == '#' && map[y][x - 1] == '#') {
        objects->boxes[i].is_in_corner = 1;
        return 1;
    }
    if (map[y][x - 1] == '#' && map[y + 1][x] == '#') {
        objects->boxes[i].is_in_corner = 1;
        return 1;
    }
    if (map[y + 1][x] == '#' && map[y][x + 1] == '#') {
        objects->boxes[i].is_in_corner = 1;
        return 1;
    }
    if (map[y][x + 1] == '#' && map[y - 1][x] == '#') {
        objects->boxes[i].is_in_corner = 1;
        return 1;
    }
    return 0;
}

int is_colliding(struct object box1, struct object box2)
{
    if (box1.x == box2.x && box1.y == box2.y)
        return 1;
    return 0;
}

int is_box_collide(struct moveables *objects, char c)
{
    for (int i = 0; i < objects->nb_box; ++i) {
        parse_boxes(objects, c, i);
    }
    return 0;
}

int is_enough_blocked_boxes(struct moveables *objects)
{
    int count = 0;

    for (int i = 0; i < objects->nb_box; ++i) {
        if (objects->boxes[i].is_in_corner == 1)
            ++count;
    }
    if ((objects->nb_box - count) < objects->nb_holes)
        return 1;
    return 0;
}
