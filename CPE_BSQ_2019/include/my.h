/*
** EPITECH PROJECT, 2019
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>

typedef struct bsq_s
{
    int big;
    int pos_big;
    int set_big;
    int set_pos;
} bsq_t;

void check_bs(char const *filepath);
void char_to_int(char *buffer, int compt, int w, int result);
int rd_ma_ch(char const *filepath);
void change(int * buffin, int result, int size, char *buffer);
void algo(int *buff, int llen, int move_llen, int size);
void biggest(int *a, int llen, int run_llen, int size);
void set_map(int x, int y, int w, char *map, char v);
int fetch_tab(int x, int y, int w, int *tab);
char fetch_map(int x, int y, int w, char *map);
void set_x(int *a, int llen, bsq_t *bsq_param, int size);
void print_map(int size, int llen, int *a);
int get_width(char *map);
int main(int ac, char const * const * av);

#endif
