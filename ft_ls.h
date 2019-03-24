/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 19:40:26 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:54:47 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <uuid/uuid.h>
# define ERROR		1
# define MONTH		1
# define DAY		2
# define TIME 		3
# define YEAR 		4
# define SIXMONTHS 	15778800
# define LOOP		0
# define DIRI		1
# define FILES		2
# define RET		3
# define L			4

typedef struct	s_args
{
	int	l;
	int	rec;
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
	struct stat			*stat;
	char				*path;
	char				*filename;
	char				*linkname;
	int					spec;
	struct s_filelst	*next;
}				t_filelst;

char			*file_getgrname(gid_t gid);
char			*file_getusername(uid_t uid);
char			*filelst_perm_str(mode_t st_mode);
char			*find_dir(char *file);
char			*find_name(char *file);
char			*follow_link(t_filelst *new);
char			*make_path(char *dir, struct dirent *entr);
char			file_getmode(mode_t st_mode);
int				add_dir(char **dir, char *str, int j);
int				add_files(char **files, char *str, int k);
int				create_filelsts(t_filelst **filelst, t_filelst **dirs,
t_args args, char *dir);
int				end_ls(int *ix);
int				error_nofile(char **dir, char **files);
int				filelst_add(t_filelst **filelst, struct dirent *entr,
char *dir);
int				filelst_count(t_filelst *lst);
int				filelst_dirs_print(t_filelst *dirs, t_args args);
int				filelst_find_add(t_filelst **filelst, char *dir,
char *filename);
int				filelst_lenname(t_filelst *filelst, int length);
int				filelst_total_blocks(t_filelst *filelst);
int				get_args(t_args *args, char **argv, int argc);
int				is_dir(char *path, int l);
int				ls_file(t_args args, char **file, size_t size);
int				ls(t_args args, char *dir);
int				not_inf(char *name);
t_args			init_args(void);
t_args			set_args(t_args args, char *str, char **argv);
void			add_to_arr(char **dir, char **files, char **argv, int *ix);
void			dirs_ls(t_args args, char **dir, int *ix);
void			file_find_print(t_filelst *filelst, t_args args, char *file);
void			filelst_free_all(t_filelst **filelst);
void			filelst_free_one(t_filelst **filelst);
void			filelst_maximums(t_filelst *ptr, t_max *max);
void			filelst_print_l(t_filelst *filelst);
void			filelst_print_noflag(t_filelst *filelst);
void			filelst_print_one(t_filelst *filelst);
void			filelst_print(t_filelst *filelst, t_args args);
void			filelst_sort_n(t_filelst **filelst);
void			filelst_sort_nr(t_filelst **filelst);
void			filelst_sort_print(t_filelst **filelst, t_args args);
void			filelst_sort_t(t_filelst **filelst);
void			filelst_sort_tr(t_filelst **filelst);
void			filelst_sort(t_filelst **filelst, t_args args);
void			filelst_swap(t_filelst **flst, t_filelst *smal,
t_filelst *prev);
void			files_ls(t_args args, char **files, int *ix);
void			init_ix(int *ix, int l);
void			no_arguments_ls(t_args args, int *ix);
void			print_time(t_filelst *ptr);
void			sort_arrs(t_args args, int *ix, char **dir, char **files);
void			start_ls(t_args args, char **dir, char **files, int *ix);

#endif
