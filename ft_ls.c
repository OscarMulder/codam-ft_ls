/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 19:39:43 by omulder        #+#    #+#                */
/*   Updated: 2019/03/23 20:38:21 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // perror

#include "ft_ls.h"

int		is_dir(char *path, int l)
{
	struct stat buf;

	if (l)
	{
		if (lstat(path, &buf) == -1)
			return (0);
	}
	else
	{
		if (stat(path, &buf) == -1)
			return (0);
	}
	return (S_ISDIR(buf.st_mode));
}

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

int		create_filelsts(t_filelst **filelst, t_filelst **dirs, t_args args,
char *dir)
{
	DIR				*dirp;
	struct dirent	*entr;

	dirp = opendir(dir);
	if (dirp == NULL)
	{
		ft_dprintf(2, "%s: %s: ", "ft_ls", find_name(dir)); // change string1
		perror("");
		return (1);
	}
	entr = readdir(dirp);
	while (entr != NULL)
	{
		if (args.a || entr->d_name[0] != '.')
			filelst_add(filelst, entr, dir);
		if (args.R && ((args.a && not_inf(entr->d_name)) ||
		entr->d_name[0] != '.') && is_dir((*filelst)->path, 1) &&
		!S_ISLNK((*filelst)->stat->st_mode))
			filelst_add(dirs, entr, dir);
		entr = readdir(dirp);
	}
	closedir(dirp);
	return (0);
}

int		ls(t_args args, char *dir)
{
	t_filelst		*filelst;
	t_filelst		*dirs;
	int				ret;

	ret = 0;
	filelst = NULL;
	dirs = NULL;
	if (create_filelsts(&filelst, &dirs, args, dir) == ERROR)
		return (ERROR);
	if ((dirs != NULL || filelst != NULL) && args.l)
		ft_printf("total %d\n", filelst_total_blocks(filelst));
	filelst_sort_print(&filelst, args);
	if (dirs != NULL && dirs->next != NULL)
		filelst_sort(&dirs, args);
	if (filelst_dirs_print(dirs, args))
		ret = 1;
	return (ret);
}

int		filelst_find_add(t_filelst **filelst, char *dir, char *filename)
{
	DIR				*dirp;
	struct dirent	*entr;

	dirp = opendir(dir);
	if (dirp == NULL)
	{
		ft_dprintf(2, "%s: %s: ", "ft_ls", find_name(dir)); // change string1
		perror("");
		return (1);
	}
	entr = readdir(dirp);
	while (entr != NULL && ft_strcmp(entr->d_name, filename) != 0)
		entr = readdir(dirp);
	if (entr != NULL && ft_strcmp(entr->d_name, filename) == 0)
		filelst_add(filelst, entr, dir);
	// else
	// 		error
	ft_strdel(&dir);
	ft_strdel(&filename);
	closedir(dirp);
	return (0);
}

int		ls_file(t_args args, char **files, size_t size)
{
	t_filelst		*filelst;
	t_filelst		*prev;
	size_t			i;
	int				ret;

	i = 0;
	ret = 0;
	filelst = NULL;
	while (i < size)
	{
		prev = filelst;
		if (filelst_find_add(&filelst, find_dir(files[i]), find_name(files[i])))
			ret = 1;
		if (filelst != prev)
		{
			filelst->filename = ft_strdup(files[i]);
			filelst->linkname = filelst->filename;
			if (S_ISLNK(filelst->stat->st_mode))
				filelst->linkname = follow_link(filelst);
		}
		else
		{
			ft_dprintf(2, "%s: %s: ", "ft_ls", files[i]); // change string1
			perror("");
			ret = 1;
		}
		i++;
	}
	filelst_sort_print(&filelst, args);
	return (ret);
}

void	file_find_print(t_filelst *filelst, t_args args, char *file)
{
	t_filelst	*single;

	while (filelst != NULL)
	{
		if (ft_strcmp(file, filelst->linkname) == 0)
		{
			single = filelst;
			single->next = NULL;
			break ;
		}
		filelst = filelst->next;
	}
	filelst_sort_print(&single, args);
}

char	*find_name(char *file)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (file[size] != '\0')
		size++;
	i = size;
	while (i >= 0 && file[i] != '/')
		i--;
	if (i >= 0)
		return (ft_strsub(file, (i + 1), (size - i)));
	return (ft_strdup(file));
}

char	*find_dir(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	while (i >= 0 && file[i] != '/')
		i--;
	if (i >= 0)
		return (ft_strsub(file, 0, i + 1));
	return (ft_strdup("."));
}

int		main(int argc, char **argv)
{
	t_args	args;
	char	**dir;
	char	**files;
	int		i;
	int		j;
	int		k;
	int		ret;

	i = 1;
	dir = (char**)ft_memalloc(sizeof(char*) * (argc + 1));
	files = (char**)ft_memalloc(sizeof(char*) * argc);
	args = init_args();
	j = 0;
	k = 0;
	ret = 0;
	dir[j] = ft_strdup(".");
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0' && ft_strcmp(argv[i], "--") != 0)
		{
			args = set_args(args, argv[i], argv);
			i++;
		}
		else
		{
			if (ft_strcmp(argv[i], "--") == 0)
				i++;
			break ;
		}
	}
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "") == 0)
		{
			ft_dprintf(2, "%s: %s: No such file or directory\n", argv[0], "fts_open");
			return (1);
		}
		if (is_dir(argv[i], args.l))
		{
			ft_strdel(&dir[j]);
			dir[j] = ft_strdup(argv[i]);
			j++;
		}
		else
		{
			files[k] = ft_strdup(argv[i]);
			k++;
		}
		i++;
	}
	i = 0;
	if (args.r && j > 1)
		ft_strarrsort_r(dir);
	else if (j > 1)
		ft_strarrsort(dir);
	if (k > 1)
		ft_strarrsort(files);
	if (j == 0 && k == 0)
		ret = ls(args, ".");
	if (ret == 1)
		return (ret);
	if (k > 0)
		ret += ls_file(args, files, (size_t)k);
	if (k > 0 && j > 0 && ret != k)
		ft_printf("\n");
	while (i < j)
	{
		if (j > 1 || (j + k) > 1)
			ft_printf("%s:\n", dir[i]);
		if (ls(args, dir[i]))
			ret = 1;
		i++;
		if (i < j)
			ft_printf("\n");
	}
	if (ret > 1)
		return (1);
	return (ret);
}
