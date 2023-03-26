/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-lou.thomas
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

char my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
