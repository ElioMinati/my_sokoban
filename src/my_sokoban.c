/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** main file for the sokoban game
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "my_sokoban.h"

int is_lose(struct moveables *objects, char **map)
{
    int nb_blocked_box = 0;

    for (int i = 0; i < objects->nb_box; ++i) {
        if (is_box_in_corner(objects, map, i))
            ++nb_blocked_box;
    }
    if (nb_blocked_box == objects->nb_box)
        return 1;
    return 0;
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; ++i) {
        mvprintw(i, 0, "%s\n", map[i]);
    }
}

void print_objects(struct moveables *objects)
{
    int x;
    int y;

    x = objects->player_x;
    y = objects->player_y;
    mvprintw(y , x, "%c", 'P');
    for (int i = 0; i < objects->nb_box; ++i) {
        x = objects->boxes[i].x;
        y = objects->boxes[i].y;
        mvprintw(y , x, "%c", 'X');
    }
}

int is_win(struct moveables *objects, char **map)
{
    int nb_full_storage = 0;

    for (int i = 0; i < objects->nb_holes; ++i) {
        for (int j = 0; j < objects->nb_box; ++j) {
            nb_full_storage += is_box_in_storage(objects, i, j);
        }
    }
    if (nb_full_storage == objects->nb_holes) {
        return 1;
    }
    return 0;
}

int my_sokoban(char **map)
{
    int key;
    struct moveables *objects = malloc(sizeof(*objects));

    init_moveables(objects, map);
    initscr();
    noecho();
    curs_set(0);
    while (is_win(objects, map) == 0 && is_lose(objects, map) == 0) {
        print_map(map);
        print_objects(objects);
        key = getch();
        move_player(objects, map, key);
        clear();
    }
    print_all(objects, map);
    refresh();
    endwin();
    if (is_lose(objects, map) == 1 && is_win(objects, map) == 0)
        return 1;
    return 0;
}
