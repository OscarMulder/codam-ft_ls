# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/13 19:44:49 by omulder        #+#    #+#                 #
#    Updated: 2019/03/13 20:14:49 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT= ./libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I./ -I./libft/
LINK = -L./libft -lft
FILES = ft_ls.c
OBJECTS = $(FILES:.c=.o)

all: $(OBJECTS) $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(INCLUDES) $(LINK) -o $(NAME) $^

$(LIBFT):
	make -C libft

$(OBJECTS): $(FILES)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
