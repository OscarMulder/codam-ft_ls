/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 19:40:26 by omulder        #+#    #+#                */
/*   Updated: 2019/03/16 20:16:28 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#define ERROR 1

typedef struct	s_args 
{
	int	l;
	int	R;
	int	a;
	int	r;
	int	t;
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

typedef struct	s_filelst
{
	struct dirent		*entr; // DO NOT TRUST IT CAN DISSAPEAR
	struct stat			*stat;
	char				*path;
	char				*filename;
	struct s_filelst	*next;
}				t_filelst;

t_args	set_args(t_args args, char *str);
t_args	init_args(void);
void	filelst_sort(t_filelst **filelst);
void	filelst_print(t_filelst *filelst);
int		filelst_lenname(t_filelst *filelst, int length);
void	filelst_add(t_filelst **filelst, struct dirent *entr, char *dir);
char	*make_path(char *dir, struct dirent *entr);
int		filelst_count(t_filelst *lst);

#endif