/*
** EPITECH PROJECT, 2022
** error_handling
** File description:
** error handling functions
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int is_map_valid(char *filename)
{
    char *buf;
    int fd = open(filename, O_RDONLY);
    struct stat st;

    stat(filename, &st);
    buf = malloc(st.st_size * sizeof(char));
    read(fd, buf, st.st_size);
    close(fd);
    for (int i = 0; buf[i] != '\0'; ++i) {
        if (buf[i] != '#' && buf[i] != ' ' && buf[i] != 'O' &&
        buf[i] != 'X' && buf[i] != 'P' && buf[i] != '\n')
            return -1;
    }
    return 0;
}

static int does_file_exist(char *filename)
{
    struct stat st;
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
        return -1;
    if (stat(filename, &st) == -1)
        return -1;
    close(fd);
    return 0;
}

int error_handling(char *map_name)
{
    if (does_file_exist(map_name) == -1) {
        write(2, "ERROR: File doesn't exist or cannot be opened\n", 46);
        return -1;
    }
    if (is_map_valid(map_name) == -1) {
        write(2, "ERROR: invalid map\n", 19);
        return -1;
    }
    return 0;
}
