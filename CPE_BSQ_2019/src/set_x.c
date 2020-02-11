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

void check_bs(char const *filepath)
{
    char buff;
    int fd = open(filepath, O_RDONLY);
    int rd = read (fd, &buff, 1);
    int cbs = 0;
    for (int i = 0; i != 100000 && rd != 0; i++) {
        rd = read (fd, &buff, 1);
        if (buff == '\n')
            cbs++;
    }
    close (fd);
    if (cbs < 2)
        exit (84);
}

void change(int * buffin, int result, int size, char *buffer)
{
    int nline = 0;
    for (int a = 0; a < size; a++) {
        if (buffer[a] != '.' && buffer[a] != 'o' && buffer[a] != '\n')
            exit (84);
        if (buffer[a] == '.')
            buffin[a] = 1;
        if (buffer[a] == 'o')
            buffin[a] = 0;
        if (buffer[a] == '\n') {
            buffin[a] = -1;
            nline++;
        }
    }
    if (nline != result && nline != 0)
        exit (84);
}

void print_map(int size, int llen, int *a)
{
    char *buffend = malloc(sizeof(char) * (size));
    for (int j = 0; j < (size/llen); j++)
    {
    for (int i = 0; i < llen; i++) {
        int v = a[llen * j + i];
        if (v == 0)
            (buffend[llen * j + i] = 'o');
        if (v == -9)
            (buffend[llen * j + i] = 'x');
        if (v > 0)
            (buffend[llen * j + i] = '.');
        if (v == -1)
            (buffend[llen * j + i] = '\n');
        }
    }
    write(1, buffend, size);
    free (a);
    free (buffend);
}

void set_x(int *a, int llen, bsq_t *bsq_param, int size)
{
    bsq_param->set_big = bsq_param->big;
    bsq_param->set_pos = bsq_param->pos_big;
    for (int j = 0; j < bsq_param->big; j++)
    {
        for (int i = 0; i < bsq_param->big; i++) {
            a[bsq_param->pos_big-- - llen * j] = -9;
        }
        bsq_param->pos_big = bsq_param->set_pos;
    }
    free (bsq_param);
    print_map(size, llen, a);
}