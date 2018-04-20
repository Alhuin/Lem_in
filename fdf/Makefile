# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/14 12:36:49 by nbettach     #+#   ##    ##    #+#        #
#    Updated: 2018/02/14 17:15:24 by nbettach    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

SRCS = fdf.c reader.c ft_bresenham.c ft_free_fdf.c

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx_macos
	gcc -g -o $@ $(FLAGS) $(OBJ) minilibx_macos/libmlx.a -framework OpenGL -framework AppKit libft/libftprintf.a

%.o: %.c
	@make -C libft
	@make -C minilibx_macos
	gcc $(FLAGS) -c $< -o $@ -I fdf.h -I libft/ft_printf.h -I minilibx_macos/mlx_new_window.h

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@make clean -C minilibx_macos
	@rm -f $(NAME)

re: fclean all
	@make re -C libft
	@make re -C minilibx_macos

.PHONY: all clean fclean re
