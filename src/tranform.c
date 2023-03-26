/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-lou.thomas
** File description:
** tranform
*/

#include "bsq.h"

int tranform(data_t *data)
{
    data->map_i = malloc(sizeof(int *) * data->li);
    for (int i = 0; i < data->li; i++) {
        data->map_i[i] = fill(data, i);
    }
    return 0;
}

int *fill(data_t *data, int i)
{
    int *stock;

    stock = malloc(sizeof(int) * data->co);
    for (int y = 0; y < data->co; y++) {
        if (data->map[i][y] == '.') {
            stock[y] = 1;
        }
        if (data->map[i][y] == 'o') {
            stock[y] = 0;
        }
    }
    return stock;
}
