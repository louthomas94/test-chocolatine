/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-lucas.midy
** File description:
** atoi
*/

int char_to_int(char *src)
{
    int nb = 0;
    int stock = 0;
    int mult = 1;

    for (int i = 0; src[i] != '\0'; i++)
        ++nb;
    for (int y = 0; y < nb - 1; y++)
        mult = mult * 10;
    for (int p = 0; p < nb; p++){
        stock = stock + (src[p] - 48) * mult;
        mult = mult / 10;
    }
    return stock;
}
