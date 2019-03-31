/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_find_add.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:16:47 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 14:17:21 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		filelst_find_add(t_filelst **filelst, char *dir, char *filename)
{
	DIR				*dirp;
	struct dirent	*entr;

	dirp = opendir(dir);
	if (dirp == NULL)
	{
		ft_dprintf(2, "%s: %s: ", "ft_ls", filename);
		perror("");
		return (1);
	}
	entr = readdir(dirp);
	while (entr != NULL && ft_strcmp(entr->d_name, filename) != 0)
		entr = readdir(dirp);
	if (entr != NULL && ft_strcmp(entr->d_name, filename) == 0)
		filelst_add(filelst, entr, dir);
	ft_strdel(&dir);
	ft_strdel(&filename);
	closedir(dirp);
	return (0);
}
