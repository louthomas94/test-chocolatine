/*
** EPITECH PROJECT, 2022
** print
** File description:
** first line
*/

#include "bsq.h"

int recup_lines(data_t *data, char *buff)
{
    int i = 0;
    char *stock;

    data->li = 0;
    for (i = 0; buff[i] != '\n'; i++);
    stock = malloc(sizeof(char) * i + 1);
    for (int y = 0; y < i; y++)
        stock[y] = buff[y];
    stock[i] = '\0';
    data->li = char_to_int(stock);
    return 0;
}

char **map_create(data_t *data, char *buff)
{
    int i = 0; data->co = 0;
    for (i = 0 ; buff[i] != '\n'; i++) {
        if (buff[i] < '0' || buff[i] > '9')
            return NULL;
    }
    i++;
    for (int y = i; buff[y] != '\n'; ++y)
        data->co += 1;
    data->map = malloc(sizeof(char *) * (data->li + 1));
    for (int z = 0; z < data->li; ++z) {
        data->map[z] = malloc(sizeof(char) * (data->co + 2));
        for (int x = 0; x < data->co + 1; ++x) {
            data->map[z][x] = buff[i];
            ++i;
        }
        data->map[z][data->co + 1] = '\0';
    }
    return data->map;
}

int verif_map(char *buff)
{
    int i = 0;
    for (i = 0; buff[i] != '\n'; i++) {
        if (buff[i] < '0' || buff[i] > '9')
            return 84;
    }
    for (int y = i; buff[y] != '\0'; y++) {
        if (buff[y] != '.' && buff[y] != 'o' && buff[y] != '\n' && buff[y] != '\0') {
            return 84;
        }
    }
    return 0;
}

int get_map(char const *filepath)
{
    data_t *data = malloc(sizeof(data_t));
    struct stat file;
    stat(filepath, &file);
    int fd;
    char *buff = malloc(sizeof(char) * (file.st_size + 1));
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return 84;
    buff[file.st_size] = '\0';
    read(fd, buff, file.st_size);
    if (my_strlen(buff) == 0)
        return 84;
    if (verif_map(buff) == 84)
        return 84;
    recup_lines(data, buff);
    map_create(data, buff);
    tranform(data);
    start_verif(data);
    close(fd);
    return 0;
}
