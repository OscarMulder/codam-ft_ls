/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_add.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:02:16 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 12:58:54 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoin3(char *str1, char *str2, char *str3)
{
	char	*temp;
	char	*new;

	temp = ft_strjoin(str1, str2);
	new = ft_strjoin(temp, str3);
	ft_strdel(&temp);
	return (new);
}

char	*follow_link(t_filelst *new)
{
	char		*buf;
	char		*str;

	buf = ft_strnew(255);
	readlink(new->path, buf, 255);
	str = ft_strjoin3(new->filename, " -> ", buf);
	ft_strdel(&buf);
	return (str);
}

int		filelst_add(t_filelst **filelst, struct dirent *entr, char *dir)
{
	t_filelst	*new;

	new = (t_filelst*)ft_memalloc(sizeof(t_filelst));
	new->spec = 0;
	new->path = make_path(dir, entr);
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
