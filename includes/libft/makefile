# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 19:18:23 by vdaviot           #+#    #+#              #
#    Updated: 2014/11/07 21:03:23 by vdaviot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strdel.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c
SRC += ft_strncat.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c 
SRC += ft_isalpha.c ft_toupper.c ft_memccpy.c ft_putstr.c ft_strequ.c
SRC += ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c
SRC += ft_strchr.c ft_strrchr.c ft_memmove.c ft_memset.c ft_memcpy.c 
SRC += ft_memchr.c ft_memcmp.c ft_bzero.c ft_atoi.c ft_strlcat.c ft_putchar.c
SRC += ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c
SRC += ft_putendl_fd.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strclr.c
SRC += ft_strnequ.c ft_strsub.c ft_striter.c ft_striteri.c ft_strmap.c 
SRC += ft_strjoin.c ft_itoa.c ft_strsplit.c ft_strtrim.c ft_lst_addbeg.c
SRC += ft_lst_create.c ft_lst_len.c ft_lst_remove_first.c ft_lst_remove.c 
SRC += ft_join.c ft_lenv_addend.c ft_lenv_create.c ft_strndup.c ft_tablen.c 
SRC += ft_strncmp_strict.c ft_strncmp.c ft_strlen_wo_c.c ft_strdup_till_c.c
SRC += ft_strcmp_strict.c ft_strcjoin.c ft_split.c ft_putendl_db.c
SRC += ft_strmapi.c ft_lst_addend.c ft_print_lst.c ft_print_lenv.c

OBJ = $(SRC:.c=.o)

HEADER = libft.h

all: $NAME

$NAME: object
	@ar rc $(NAME) $(OBJ)
object:
	@gcc -c $(SRC)
clean:
	@/bin/rm -f $(OBJ)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
