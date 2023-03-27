##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	src/bsq.c			\
		src/start.c			\
		src/tranform.c		\
		src/verif_algo.c	\
		src/generating_map.c	\

SRC_TEST	=	tests/test.c	\

SRC_MAIN	=	src/main.c	\

OBJ	=	$(SRC:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

NAME	=	bsq

NAME_TEST	=	unit_tests

CFLAGS	=	-Wall -Wextra -g3

CPPFLAGS	=	-I include

LD_FLAGS	=	-L lib/ -lbsq

TEFLAGS	=	-lcriterion --coverage

all:	$(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
		make -C lib/
		$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LD_FLAGS) $(CFLAGS)

clean:
	make clean -C lib/
	$(RM) $(OBJ)
	$(RM) $(OBJ_MAIN)

fclean: clean
	make fclean -C lib/
	$(RM) $(NAME)

re: fclean all

fclean_tests: fclean
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) $(NAME_TEST)

unit_tests: fclean $(NAME)
	make -C lib/
	$(CC) -o $(NAME_TEST) $(SRC_TEST) $(SRC) $(CFLAGS) \
	$(CPPFLAGS) $(TEFLAGS) $(LD_FLAGS)

tests_run: unit_tests
	./$(NAME_TEST)
	gcovr --exclude tests/ --branches

.PHONY: all clean fclean re fclean_tests unit_tests tests_run
