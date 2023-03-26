/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-lou.thomas
** File description:
** generating_map
*/

#include "bsq.h"

int error(char **av)
{
    if (av[1][0] < '0' || av[1][0] > '9')
        return 84;
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] != '.' && av[2][i] != 'o' && av[2][i] != '\n' && av[2][i] != '\0')
            return 84;
    }
    generating(av);
    return 0;
}

int generating(char **av)
{
    data_t data;
    data.li = char_to_int(av[1]);
    data.co = char_to_int(av[1]);
    char *str = av[2];
    int z = 0;
    data.map = malloc(sizeof(char *) * data.li + 1);
    for (int i = 0; i < data.li; i++) {
        data.map[i] = malloc(sizeof(char) * data.co + 2);
        for (int y = 0; y < data.co; y++) {
            data.map[i][y] = str[z];
            z++;
            verif_z(&z, av);
        }
        data.map[i][data.co] = '\n';
        data.map[i][data.co + 1] = '\0';
    }
    tranform(&data);
    start_verif(&data);
    return 0;
}

int verif_z(int *z, char **av)
{
    int a = my_strlen(av[2]);
    if (*z == a) {
        *z = 0;
    }
    return 0;
}
