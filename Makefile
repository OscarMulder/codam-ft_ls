# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/13 19:44:49 by omulder        #+#    #+#                 #
#    Updated: 2019/03/28 11:46:54 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT= ./libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I./ -I./libft/ -I./includes
LINK = -L./libft -lft
VPATH = ./srcs
FILES = ft_ls.c set_args.c init_args.c filelst_add.c filelst_lenname.c \
filelst_print.c filelst_sort.c filelst_count.c filelst_print_one.c \
filelst_print_noflag.c filelst_print_l.c filelst_total_blocks.c \
filelst_sort_t.c filelst_sort_tr.c filelst_swap.c filelst_sort_nr.c \
filelst_sort_n.c filelst_dirs_print.c filelst_free_all.c filelst_free_one.c \
is_dir.c make_path.c not_inf.c create_filelsts.c ls.c filelst_find_add.c \
ls_file.c file_find_print.c find_name.c find_dir.c get_args.c add_dir.c \
add_files.c error_nofile.c init_ix.c sort_arrs.c add_to_arr.c files_ls.c \
no_arguments_ls.c dirs_ls.c start_ls.c end_ls.c file_getusername.c \
file_getgrname.c file_getmode.c filelst_perm_str.c print_time.c \
filelst_maximums.c
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

norm:
	@norminette $(FILES) ft_ls.h