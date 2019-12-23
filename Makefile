# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 17:18:07 by npetrell          #+#    #+#              #
#    Updated: 2019/12/23 20:42:55 by npetrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

GCC = gcc

LIBFT = libft

FRAM = -framework OpenGL -framework Appkit

LFLAGS = -L $(LIBFT) -lft

SRCS = ./main.c ./key_and_mouse_press.c ./draw_map.c ./check_valid.c \
./atoi_hex.c ./create_map.c ./rotate.c \

OBJECTS = $(SRCS:%.c=%.o)

HEADERS = includes/ libft/includes

vpath %.c srcs/
vpath %.h includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)
	$(GCC) -o $(NAME) $(OBJECTS) $(LFLAGS) $(FRAM) -lmlx

%.o: %.c
	$(GCC) -I $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all


