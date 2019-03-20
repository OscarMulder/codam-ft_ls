# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/13 19:44:49 by omulder        #+#    #+#                 #
#    Updated: 2019/03/20 11:24:49 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT= ./libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I./ -I./libft/
LINK = -L./libft -lft
FILES = ft_ls.c set_args.c init_args.c filelst_add.c filelst_lenname.c \
filelst_print.c filelst_sort.c filelst_count.c filelst_print_one.c \
filelst_print_noflag.c filelst_print_l.c filelst_total_blocks.c \
filelst_sort_t.c filelst_sort_tr.c filelst_swap.c filelst_sort_r.c
OBJECTS = $(FILES:.c=.o)

all: $(OBJECTS) $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(INCLUDES) $(LINK) -o $(NAME) $^

$(LIBFT):
	make -C libft

$(OBJECTS): $(FILES)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

clean:
	@rm -f $(OBJECTS)
	@make -C libft clean
	
fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
