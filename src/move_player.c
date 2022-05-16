/*
** EPITECH PROJECT, 2022
** move_player.c
** File description:
** functions used to move the player
*/

#include "my_sokoban.h"

void move_left(struct moveables *objects, char **map)
{
    int px = objects->player_x - 1;
    int py = objects->player_y;
    int bx;
    int by;

    objects->player_x -= 1;
    for (int i = 0; i < objects->nb_box; ++i) {
        bx = objects->boxes[i].x;
        by = objects->boxes[i].y;
        if (px == bx && py == by && map[by][bx - 1] != '#') {
            objects->boxes[i].x -= 1;
        } else if (px == bx && py == by) {
            objects->player_x += 1;
        }
    }
    is_box_collide(objects, 'l');
}

void move_right(struct moveables *objects, char **map)
{
    int px = objects->player_x + 1;
    int py = objects->player_y;
    int bx;
    int by;

    objects->player_x += 1;
    for (int i = 0; i < objects->nb_box; ++i) {
        bx = objects->boxes[i].x;
        by = objects->boxes[i].y;
        if (px == bx && py == by && map[by][bx + 1] != '#') {
            objects->boxes[i].x += 1;
        } else if (px == bx && py == by) {
            objects->player_x -= 1;
        }
    }
    is_box_collide(objects, 'r');
}

void move_player(struct moveables *objects, char **map, int key)
{
    int x = objects->player_y;
    int y = objects->player_x;

    if (key == 65 && map[x - 1][y] != '#')
        move_up(objects, map);
    if (key == 66 && map[x + 1][y] != '#')
        move_down(objects, map);
    if (key == 67 && map[x][y + 1] != '#')
        move_right(objects, map);
    if (key == 68 && map[x][y - 1] != '#')
        move_left(objects, map);
}
