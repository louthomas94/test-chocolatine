##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	atoi.c	\
		my_putstr.c	\
		my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libbsq.a

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ../include

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
