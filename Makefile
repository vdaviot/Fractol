# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/02 15:28:04 by vdaviot           #+#    #+#              #
#    Updated: 2016/04/19 16:02:47 by vdaviot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c draw/draw.c draw/ft_put_pixel_img.c fractal/fractal.c 
SRC += fractal/julia.c color/coloration.c fractal/ship.c 
SRC += fractal/triforce.c opti/complex.c color/orbit_trap.c opti/threading.c 
SRC += key/key1.c key/key2.c key/key3.c color/smooth.c key/key_color.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/libft

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) -L includes/libft -lft -lmlx $(OBJ) -o $(NAME) -I\
		includes/libft/libft.h includes/libft/libft.a -framework OpenGL \
		-framework AppKit -funroll-loops -pipe -Ofast -march=native
		@echo "compile to $(NAME) DONE !"
clean:
		@rm -f $(OBJ)
		@echo "clean of object done !"
fclean: clean
		@rm -f $(NAME)
		@echo "fclean $(NAME) done !"
re: fclean all

.PHONY: re clean fclean run all
