/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_

    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <stdio.h>

typedef struct data_s {
    int li;
    int co;
    char **map;
    int **map_i;
    int big_nb;
    int nb_x;
    int nb_y;
} data_t;

int get_map(char const *filepath);
int char_to_int(char *src);
char my_putstr(char const *str);
void my_putchar(char c);
int tranform(data_t *data);
int *fill(data_t *data, int i);
int start_verif(data_t *data);
int verif(data_t *data, int x, int y);
int bsq(int ac, char **av);
int recup_lines(data_t *data, char *buff);
int char_to_int(char *src);
int map_c(data_t *data, char *buff, int i, int z);
int generating(char **av);
int my_strlen(char const *str);
int error(char **av);
int verif_z(int *z, char **av);

#endif /* !bsq */
