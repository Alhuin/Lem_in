# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/24 16:01:49 by nbettach     #+#   ##    ##    #+#        #
#    Updated: 2018/03/17 16:12:05 by nbettach    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -ggdb

RM = rm -f

SOURCES = $(addsuffix .c, ft_atoi ft_bzero ft_countwords ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_lstmap ft_lstiter ft_lstdelone ft_lstadd  ft_lstnew ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strstr ft_strsub ft_strsplit ft_strtrim ft_tolower ft_toupper ft_swap ft_itos_lower ft_itos_upper ft_putwchar ft_strlen ft_putnbrbase ft_itoabase ft_strrev ft_wcharlen ft_wstrlen ft_partlen ft_pow ft_wstrnew ft_wstrndup ft_strndup ft_strnewchar ft_wstrnewchar ft_wstrjoin ft_putwstr ft_printf handle_args handle_nbrs handle_option handle_prec handle_strings handle_wide handle_wide_str save_args ft_wstrdup init_organize ft_abs get_next_line ft_realloc ft_sqrt)

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
		@(echo "\033[32m Librairie :[ \033[31m\t\c")
		@(echo "$@ \033[32m]\033[0m \033[0K")
		@($(CC) -g $(CFLAGS) -c -o $@ $<)
		@(echo "\033[2F")

$(NAME): $(OBJECT)
		@(ar rc $(NAME) $(OBJECT))
		@(ranlib $(NAME))
		@(echo "\033[2K\033[2F")
		@(echo "\n\033[32m Librairie compilée\033[0m";)


clean:
		@($(RM) $(OBJECT))
		@echo "\033[1;34mLibft\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
		@($(RM) $(NAME))
		@echo "\033[1;34mLibft\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"
		
re: fclean all

.PHONY: clean fclean re
