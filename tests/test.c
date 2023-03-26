/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "bsq.h"

Test(bsq, Test_map, .init = cr_redirect_stdout)
{
    char **line = malloc(sizeof(char) * 2);
    line[0] = malloc(sizeof(char) * 6);
    line[1] = malloc(sizeof(char) * 14);
    line[0] = "./bsq\0";
    line[1] = "tests/map.txt\0";
    bsq(2, line);
    cr_assert_stdout_eq_str("......o.......o.....\n...xxxxxx...........\n...xxxxxx...........\n...xxxxxx...........\no..xxxxxx.......o...\n..oxxxxxxo..........\n...xxxxxx.......o...\n....................\n........o.o.........\n.......o.o..........\n....................\no...................\n.o.....o..o.........\n..o..............o..\n..........o.........\n");
}

Test(bsq, test_error_handling1) {
    int ac = 2;
    char **av = malloc(sizeof(char *) * 3);
    av[0] = malloc(sizeof(char) * 6);
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char) * 17);
    av[1] = "tests/map12.txt\0";
    av[2] = NULL;
    cr_assert(bsq(ac, av) == 84);
}

Test(bsq, test_error_handling2) {
    int ac = 3;
    char **av = malloc(sizeof(char *) * 3);
    av[0] = malloc(sizeof(char) * 6);
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char) * 15);
    av[1] = "tests/map.txt\0";
    av[2] = NULL;
    cr_assert(bsq(ac, av) == 84);
}

Test(bsq, test_error_handling3) {
    int ac = 1;
    char **av = malloc(sizeof(char *) * 3);
    av[0] = malloc(sizeof(char) * 6);
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char) * 15);
    av[1] = "tests/map.txt\0";
    av[2] = NULL;
    cr_assert(bsq(ac, av) == 84);
}

Test(bsq, test_error_handling4) {
    int ac = 2;
    char **av = malloc(sizeof(char *) * 3);
    av[0] = malloc(sizeof(char) * 6);
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char) * 16);
    av[1] = "tests/map3.txt\0";
    av[2] = NULL;
    cr_assert(bsq(ac, av) == 84);
}

Test(bsq, test_error_handling5) {
    int ac = 2;
    char **av = malloc(sizeof(char *) * 3);
    av[0] = malloc(sizeof(char) * 6);
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char) * 8);
    av[1] = "tests/\0";
    av[2] = NULL;
    cr_assert(bsq(ac, av) == 84);
}

Test(bsq, test_error_handling6) {
    int ac = 2;
    char **av = malloc(sizeof(char *) * 3);
    av[0] = malloc(sizeof(char) * 6);
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char) * 16);
    av[1] = "tests/map4.txt\0";
    av[2] = NULL;
    cr_assert(bsq(ac, av) == 84);
}

Test(bsq, test_error_handling7) {
    int ac = 3;
    char **av = malloc(sizeof(char *) * 3);
    av[0] = malloc(sizeof(char) * 6);
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char) * 3);
    av[1] = "10\0";
    av[2] = malloc(sizeof(char) * 8);
    av[2] = "..oo..p\0";
    cr_assert(bsq(ac, av) == 84);
}

Test(bsq, test_error_handling8) {
    int ac = 2;
    char **av = malloc(sizeof(char *) * 3);
    av[0] = malloc(sizeof(char) * 6);
    av[0] = "./bsq\0";
    av[1] = malloc(sizeof(char) * 7);
    av[1] = "..oo..\0";
    av[2] = NULL;
    cr_assert(bsq(ac, av) == 84);
}
