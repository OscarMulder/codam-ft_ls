/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 19:39:43 by omulder        #+#    #+#                */
/*   Updated: 2019/03/20 15:09:53 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dir(char *path)
{
	struct stat buf;

	if (stat(path, &buf) == -1)
		return (0);
	return (S_ISDIR(buf.st_mode));
}

/*
** should add check to see if dir ends with '/'
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

int		not_inf(char *name)
{
	if (ft_strcmp(name, ".") == 0)
		return (0);
	if (ft_strcmp(name, "..") == 0)
		return (0);
	return (1);
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
		if (args.R && ((args.a && not_inf(entr->d_name)) || entr->d_name[0] != '.') && is_dir(filelst->path) && !S_ISLNK(filelst->stat->st_mode))
			filelst_add(&dirs, entr, dir);
		entr = readdir(dirp);
	}
	if (filelst != NULL)
	{
		if (args.r)
		{
			if (args.t)
				filelst_sort_tr(&filelst);
			else
				filelst_sort_r(&filelst);
		}
		else
		{
			if (args.t)
				filelst_sort_t(&filelst);
			else
				filelst_sort(&filelst);
		}
		filelst_print(filelst, args);
	}
	closedir(dirp);
	if (dirs != NULL && dirs->next != NULL)
	{
		if (args.r)
		{
			if (args.t)
				filelst_sort_tr(&dirs);
			else
				filelst_sort_r(&dirs);
		}
		else
		{
			if (args.t)
				filelst_sort_t(&dirs);
			else
				filelst_sort(&dirs);
		}
	}
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
		if (argv[i][0] == '-')
			args = set_args(args, argv[i], argv);
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
