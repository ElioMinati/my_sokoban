/*
** EPITECH PROJECT, 2022
** get_map.c
** File description:
** functions used to get the map from the file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char **get_map(char *filename)
{
    char **map;
    char *buf;
    int fd = open(filename, O_RDONLY);
    struct stat st;

    stat(filename, &st);
    buf = malloc(st.st_size * sizeof(char));
    read(fd, buf, st.st_size);
    map = my_str_to_word_array_lj(buf);
    close(fd);
    return map;
}
