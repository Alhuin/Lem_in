# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/17 13:51:41 by nbettach     #+#   ##    ##    #+#        #
#    Updated: 2018/03/17 16:12:43 by nbettach    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = nbettach.filler
INC = ./includes
FILLER = filler.c init_box_poss.c filling.c tools.c parser.c zoning.c move.c tools_next.c ft_start_algo.c
SRC = $(addprefix ./src/, $(FILLER))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -Wall -Wextra -Werror $(SRC) -L. libft/libftprintf.a -o $(NAME)

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
