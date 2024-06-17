##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	src/hash.c				\
		src/new_hashtable.c		\
		src/delete_hashtable.c	\
		src/ht/insert.c			\
		src/ht/delete.c			\
		src/ht/search.c			\
		src/ht/dump.c			\
		lib/my/my_strlen.c		\
		lib/my/my_strcmp.c		\
		lib/my/mini_printf.c	\
		lib/my/my_put_nbr.c		\
		lib/my/my_putchar.c		\
		lib/my/my_putstr.c		\

TEST=	tests/unitests.c				\
		tests/functionnal_tests.c		\
		src/ht/search.c			\
		src/ht/delete.c			\
		src/ht/dump.c			\
		src/ht/insert.c			\
		src/hash.c				\
		src/new_hashtable.c		\
		src/delete_hashtable.c	\
		lib/my/my_strlen.c		\
		lib/my/my_strcmp.c		\
		lib/my/mini_printf.c	\
		lib/my/my_put_nbr.c		\
		lib/my/my_putchar.c		\
		lib/my/my_putstr.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libcypher.a

TEST_NAME	=	unit_tests

CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc -o $(NAME) $(OBJ)

debug:	CFLAGS += -g3

debug:	re

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

fclean_all:	fclean
		rm -rf $(TEST_NAME)

tests_run:
		$(CC) $(TEST) -o $(TEST_NAME) -lcriterion
		./$(TEST_NAME)

re:		fclean all

.PHONY:	all debug clean fclean fclean_all tests_run re
