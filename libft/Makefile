# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 11:10:43 by omulder        #+#    #+#                 #
#    Updated: 2019/03/22 13:51:20 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I./includes
FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c  \
	ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	ft_memccpy.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putstrarr.c ft_putstrarri.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdcount.c \
	ft_strdel.c ft_strcat.c ft_strdlen.c ft_strdup.c ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
	ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_printline.c \
	ft_putnstr.c ft_memchr.c ft_intlen.c ft_lstcount.c ft_lstaddback.c \
	ft_strarrsort.c ft_strarrsort_r.c
OBJECTS = $(FILES:.c=.o)

all: $(OBJECTS) $(NAME)

$(NAME): $(OBJECTS)
	make -C ft_printf re
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(FILES)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

clean:
	@rm -f $(OBJECTS)
	@make -C ft_printf clean
	
fclean: clean
	@rm -f $(NAME)
	@make -C ft_printf fclean

re: fclean all

norm:
	@norminette $(shell find . -name "ft_*") libft.h