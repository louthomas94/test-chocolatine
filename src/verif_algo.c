/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-lou.thomas
** File description:
** verif_algo
*/

#include "bsq.h"

int replace(data_t *data)
{
    for (int i = 0; i < data->big_nb; i++) {
        for (int y = 0; y < data->big_nb ; y++)
            data->map[data->nb_x + i][data->nb_y + y] = 'x';
    }
    return 0;
}

int coo_nb(data_t *data)
{
    int i = 0; int y = 0; int a = 0; int b = 0;
    while (a < data->li) {
        if (data->map_i[a][b] > data->big_nb)
            data->big_nb = data->map_i[a][b];
        b++;
        if (b >= data->co) {
            b = 0;
            a++;
        }
    } while (y < data->li) {
        if (data->map_i[y][i] == data->big_nb) {
            data->nb_x = y - (data->big_nb - 1);
            data->nb_y = i - (data->big_nb - 1);
            break;
        }
        i++;
        if (i == data->co) {
            i = 0;
            y++;
        } } return 0;
}

int start_verif(data_t *data)
{
    data->big_nb = 0;
    for (int x = 1; x < data->li; x++) {
        for (int y = 1; y < data->co; y++) {
            verif(data, x, y);
        }
    }
    coo_nb(data);
    replace(data);
    for (int i = 0; i < data->li; i++) {
        write(1, data->map[i], data->co + 1);
    }
    return 0;
}

int verif(data_t *data, int x, int y)
{
    int stock = 0; int top = data->map_i[x - 1][y];
    int left = data->map_i[x][y - 1];
    int left_top = data->map_i[x - 1][y - 1];
    if (data->map_i[x][y] == 0)
        return 0;
    if (top == 0 || left == 0 || left_top == 0)
        return 0;
    if (left < top)
        stock = left;
    else
        stock = top;
    if (stock > left_top)
        stock = left_top;
    data->map_i[x][y] = data->map_i[x][y] + stock;
    return 0;
}
