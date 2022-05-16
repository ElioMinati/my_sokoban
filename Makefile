##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile for minishell1
##

SRC	=	main.c	\
		src/my_sokoban.c	\
		src/error_handling.c	\
		src/get_map.c 	\
		src/get_objects.c	\
		src/move_object.c	\
		src/move_player.c	\
		src/init.c	\
		src/conditions.c	\
		src/parse.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-Llib/my/ -lmy

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-Iinclude/

CCRITERION	= 	--coverage -lcriterion

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -lcurses

tests_run:
	$(RM) *.gcda
	$(RM) *.gcno
	make -C lib/my/
	$(CC) -o unit_tests $(FILES) $(TESTS) $(CFLAGS) $(CPPFLAGS) $(CCRITERION)
	./unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C lib/my
	$(RM) $(NAME)
	$(RM) unit_tests
	$(RM) *.gcno
	$(RM) *.gcda

re: fclean all

.PHONY : all re clean tests_run fclean
