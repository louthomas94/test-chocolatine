/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-lou.thomas
** File description:
** start
*/

#include "bsq.h"

int bsq(int ac, char **av)
{
    if (ac < 2 && ac >= 4) {
        return 84;
    }
    if (ac == 3) {
        if (error(av) == 84)
            return 84;
        return 0;
    } else {
        if (ac != 2)
            return 84;
        char const *filepath = av[1];
        if (get_map(filepath) == 84)
            return 84;
    }
    return 0;
}
