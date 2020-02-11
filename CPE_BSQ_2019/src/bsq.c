/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

void biggest(int *a, int llen, int run_llen, int size)
{
    bsq_t *bsq_param = malloc(sizeof(bsq_t));
    bsq_param->pos_big = 0;
    bsq_param->big = 0;
    run_llen = 0;
    int compt = 0;
    while (compt <= size - 1) {
        if (a[run_llen] > bsq_param->big) {
            bsq_param->big = a[run_llen];
            bsq_param->pos_big = run_llen;
        }
        run_llen++;
        compt++;
    }
    set_x(a, llen, bsq_param, size);
}

int get_width(char *map)
{
    int x = 0;
    while ((map[x]) != '\n') {
        x += 1;
    }
    return (x);
}

int rd_ma_ch(char const *filepath)
{
    check_bs(filepath);
    int llen = 0;
    int i, w;
    char *buffer;
    int result = 0;
    struct stat sb;
    stat(filepath, &sb);
    int h = sb.st_size;
    char *map = malloc(sizeof(char) * (h + 1));
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit (84);
    read(fd, map, h);
    for (i = 0; map[i] != '\n'; i++) {
        result = result * 10 + (map[i] - 48);
        if ((map[i]) < 48 || (map[i]) > 57)
            return (84);
    }
    for (w = 0; *(map + i + 1 + w) != '\n'; w++);
    char_to_int(map + i + 1, h - (i + 1), w, result);
}

void char_to_int(char *buffer, int size, int w, int result)
{
    int llen = 0;
    int x = 0;
    int *buffin = malloc(sizeof(int) * (size + 1));
    change(buffin, result, size, buffer);
    while ( buffin[x] != -1) {
        llen++;
        x++;
    }
    llen = llen + 1;
    int move_llen = llen;
    for (int n = 0; n <= size; n++) {
        if (buffin[move_llen] == -1) {
            move_llen += 1;
            n += 2;
        }
        algo (buffin, llen, move_llen, size);
        move_llen++;
    }
    biggest (buffin, llen, move_llen, size);
}

void algo(int *buff, int llen, int move_llen, int size)
{
    int small;
    if (move_llen + 1 >= size)
        return;
    if (buff[move_llen + 1] != 0 && buff[move_llen + 1] != -1) {
        small = buff[move_llen];
        if (buff[move_llen] <= small)
            small = buff[move_llen];
        if (buff[move_llen - llen + 1] <= small)
            small = buff[move_llen - llen + 1];
        if (buff[move_llen - llen] <= small)
            small = buff[move_llen - llen];
        buff[move_llen + 1] = small + 1;
    }
}