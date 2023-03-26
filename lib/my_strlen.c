/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-lou.thomas
** File description:
** my_strlen
*/

#include "bsq.h"

int my_strlen(char const *str)
{
    int rep = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        rep = rep + 1;
    }
    return rep;
}
