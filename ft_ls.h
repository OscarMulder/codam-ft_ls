/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 19:40:26 by omulder        #+#    #+#                */
/*   Updated: 2019/03/22 17:42:16 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#define ERROR		1
#define MONTH		1
#define DAY			2
#define TIME 		3
#define YEAR 		4
#define SIXMONTHS 	15552000

typedef struct	s_args 
{
	int	l;
	int	R;
	int	a;
	int	r;
	int	t;
	int one;
}				t_args;

typedef struct	s_print 
{
	int	row;
	int	length;
	int	coli;
	int	total;
	int	printed;
	int	extra;
	int	col;
	int	left;

}				t_print;

typedef struct	s_max
{
	int	link;
	int	username;
	int	groupname;
	int	size;
	int	major;
	int	minor;
}				t_max;


typedef struct	s_filelst
{
	struct dirent		*entr; // DO NOT TRUST IT CAN DISSAPEAR
	struct stat			*stat;
	char				*path;
	char				*filename;
	char				*linkname;
	int					spec;
	struct s_filelst	*next;
}				t_filelst;

int		ls(t_args args, char *dir);
t_args	set_args(t_args args, char *str, char **argv);
t_args	init_args(void);
int		filelst_total_blocks(t_filelst *filelst);
void	filelst_sort_n(t_filelst **filelst);
void	filelst_sort_nr(t_filelst **filelst);
void	filelst_sort(t_filelst **filelst, t_args args);
void	filelst_sort_print(t_filelst **filelst, t_args args);
void	filelst_dirs_print(t_filelst *dirs, t_args args);
void	filelst_print(t_filelst *filelst, t_args args);
void	filelst_print_one(t_filelst *filelst);
void	filelst_print_l(t_filelst *filelst);
void	filelst_print_noflag(t_filelst *filelst);
int		filelst_lenname(t_filelst *filelst, int length);
int		filelst_add(t_filelst **filelst, struct dirent *entr, char *dir);
char	*make_path(char *dir, struct dirent *entr);
int		filelst_count(t_filelst *lst);
void	filelst_swap(t_filelst **flst, t_filelst *smal, t_filelst *prev);
void	filelst_sort_t(t_filelst **filelst);
void	filelst_sort_tr(t_filelst **filelst);
void	file_find_print(t_filelst *filelst, t_args args, char *file);
int		ls_file(t_args args, char **file, size_t size);
int		create_filelsts(t_filelst **filelst, t_filelst **dirs, t_args args, char *dir);
int		not_inf(char *name);
char	*find_dir(char *file);
char	*find_name(char *file);
char	*follow_link(t_filelst *new);

#endif