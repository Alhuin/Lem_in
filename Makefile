# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/17 13:51:41 by nbettach     #+#   ##    ##    #+#        #
#    Updated: 2018/04/26 13:47:19 by jjanin-r    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem-in
INC = ./includes
LEMIN = main.c read_ants.c read_links.c make_matrice.c free.c utils.c
SRC = $(addprefix ./src/, $(LEMIN))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -fsanitize=address -g -Wall -Wextra -Werror $(SRC) -L. libft/libftprintf.a -o $(NAME)

%.o : %.c
	gcc -Wall -Werror -Wextra -o $@ -c $< -I $(INC)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
