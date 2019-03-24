/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ls_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:18:03 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:49:59 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	set_correct_filename(t_filelst *filelst, char *str)
{
	if (filelst->linkname != filelst->filename)
		ft_strdel(&filelst->linkname);
	ft_strdel(&filelst->filename);
	filelst->filename = ft_strdup(str);
	filelst->linkname = filelst->filename;
	if (S_ISLNK(filelst->stat->st_mode))
		filelst->linkname = follow_link(filelst);
}

static int	print_error(char *str)
{
	ft_dprintf(2, "%s: %s: ", "ft_ls", str);
	perror("");
	return (1);
}

int			ls_file(t_args args, char **files, size_t size)
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
			set_correct_filename(filelst, files[i]);
		else
			ret = print_error(files[i]);
		i++;
	}
	filelst_sort_print(&filelst, args);
	filelst_free_all(&filelst);
	return (ret);
}
