/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main for solostumper
*/

#include <unistd.h>
#include "my.h"
#include "my_sokoban.h"

static void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n");
    my_putstr("          'P' for the player, 'X' for boxes and ");
    my_putstr("'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "ERROR: invalid number of parameters\n", 36);
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 1) {
        display_usage();
        return 0;
    }
    if (error_handling(av[1]) == -1)
        return 84;
    return my_sokoban(get_map(av[1]));
}
