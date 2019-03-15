/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 19:39:43 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 20:44:52 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dir(char *path)
{
	struct stat buf;

	if (stat(path, &buf) == -1)
		exit(ERROR);
	return (S_ISDIR(buf.st_mode));
}

/*
** should at check to see if dir ends with '/'
*/

char	*make_path(char *dir, struct dirent *entr)
{
	char *temp;
	char *path;

	temp = ft_strjoin(dir, "/");
	path = ft_strjoin(temp, entr->d_name);
	ft_strdel(&temp);
	return (path);
}

int		ls(t_args args, char *dir)
{
	DIR				*dirp;
	struct dirent	*entr;
	t_filelst		*filelst;
	t_filelst		*dirs;

	dirp = opendir(dir);
	if (dirp == NULL)
		return (1);
	entr = readdir(dirp);
	filelst = NULL;
	dirs = NULL;
	while (entr != NULL)
	{
		if (args.a || entr->d_name[0] != '.')
			filelst_add(&filelst, entr, dir);
		if (args.R && entr->d_name[0] != '.' && is_dir(filelst->path))
			filelst_add(&dirs, entr, dir);
		entr = readdir(dirp);
	}
	filelst_sort(&filelst);
	filelst_print(filelst);
	ft_printf("\n");
	closedir(dirp);
	if (dirs != NULL && dirs->next != NULL)
		filelst_sort(&dirs);
	while (args.R && dirs != NULL)
	{
		ft_printf("\n%s:\n", dirs->path);
		ls(args, dirs->path);
		dirs = dirs->next;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_args	args;
	char	*dir;
	int		i;

	i = 1;
	args = init_args();
	dir = ft_strdup(".");
	while (i < argc)
	{
		if (argv[1][0] == '-')
			args = set_args(args, argv[1]);
		else
		{
			ft_strdel(&dir);
			dir = ft_strdup(argv[i]);
		}
		i++;
	}
	ls(args, dir);
	return (0);
}
