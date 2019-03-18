# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:19:48 by mtordjma          #+#    #+#              #
#    Updated: 2019/01/25 14:08:01 by mtordjma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
GCC2 = clang -Wall -Wextra -Werror
SRCS = ft_checkchar.c \
		ft_connect.c \
		ft_listadd.c \
		ft_listdel.c \
		ft_listnew.c \
		ft_printerror.c \
		ft_stock.c \
		ft_mapping.c \
		ft_print_map.c \
		ft_patern_creation.c \
		ft_backtrack.c \
		ft_place_or_remove.c \
		main.c

OBJ = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make re -C ./libft
	$(GCC2) $(OBJ) libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/
re: fclean $(NAME)
