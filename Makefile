##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Aurélien Vandaële <aurelien.vandaele@epitech.eu>
##

SRC	=	src/main.c			\
		src/matchstick.c		\
		src/print.c			\
		src/get_next_line.c		\
		src/fill_array.c		\
		src/fill_c_line_matches.c	\
		src/condition_line_matches.c	\
		src/my_ai.c

NAME	=	matchstick

OBJ	=	$(SRC:.c=.o)

COMPIL	=	-lmy -Llib/my

CFLAGS	=	-W -Wall -Werror -Wextra -I include/  -g

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(OBJ) $(COMPIL) $(CFLAGS)
		make clean

clean:
		rm -f $(OBJ)
		rm -rf *~ src/*~ include/*~ lib/*~ lib/my/*~
		rm -f vgcore*

fclean:		clean
		make fclean -C lib/my
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean
