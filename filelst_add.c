/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_add.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:02:16 by omulder        #+#    #+#                */
/*   Updated: 2019/03/22 16:53:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*follow_link(t_filelst *new)
{
	char		*buf;

	buf = ft_strnew(255);
	readlink(new->path, buf, 255);
	//ft_printf("%s -> %s\n", new->path, buf);
	return (ft_strjoin(ft_strjoin(new->filename, " -> "), buf)); //LEAK
}

int		filelst_add(t_filelst **filelst, struct dirent *entr, char *dir)
{
	t_filelst	*new;

	new = (t_filelst*)ft_memalloc(sizeof(t_filelst));
	new->spec = 0;
	new->path = make_path(dir, entr);
	new->entr = entr;
	new->stat = (struct stat*)ft_memalloc(sizeof(struct stat));
	if (lstat(new->path, new->stat) == -1)
		return (ERROR);
	new->filename = ft_strdup(entr->d_name);
	new->linkname = new->filename;
	if (S_ISLNK(new->stat->st_mode))
		new->linkname = follow_link(new);
	new->next = *filelst;
	*filelst = new;
	return (0);
}
