/*
** EPITECH PROJECT, 2022
** my_sokoban.h
** File description:
** my_sokoban function prototypes, header file
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

struct object {
    int x;
    int y;
    int is_in_corner;
};

struct moveables {
    int player_x;
    int player_y;
    struct object *boxes;
    struct object *holes;
    int nb_holes;
    int nb_box;
};

int my_sokoban(char **map);

char **get_map(char *filename);

void init_moveables(struct moveables *objects, char **map);

void move_player(struct moveables *objects, char **map, int key);

void get_mv_objects(struct moveables *objects, char **map);

int get_nb_boxes(char **map);

int get_nb_holes(char **map);

int is_box_in_storage(struct moveables *objects, int i, int j);

int is_box_next(struct moveables *objects, int bx, int by, char c);

int is_box_in_corner(struct moveables *objects, char **map, int i);

int is_colliding(struct object box1, struct object box2);

void parse_boxes(struct moveables *objects, char c, int i);

void move_up(struct moveables *objects, char **map);

void move_down(struct moveables *objects, char **map);

int is_box_collide(struct moveables *objects, char c);

int error_handling(char *map_name);

void print_objects(struct moveables *objects);

void print_map(char **map);

void print_all(struct moveables *objects, char **map);

#endif /* !MY_SOKOBAN_H_ */
