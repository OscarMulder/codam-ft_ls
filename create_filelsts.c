/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_filelsts.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:10:56 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:51:17 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		create_filelsts(t_filelst **filelst, t_filelst **dirs, t_args args,
char *dir)
{
	DIR				*dirp;
	struct dirent	*entr;

	dirp = opendir(dir);
	if (dirp == NULL)
	{
		ft_dprintf(2, "%s: %s: ", "ft_ls", find_name(dir));
		perror("");
		return (1);
	}
	entr = readdir(dirp);
	while (entr != NULL)
	{
		if (args.a || entr->d_name[0] != '.')
			filelst_add(filelst, entr, dir);
		if (args.rec && ((args.a && not_inf(entr->d_name)) ||
		entr->d_name[0] != '.') && is_dir((*filelst)->path, 1) &&
		!S_ISLNK((*filelst)->stat->st_mode))
			filelst_add(dirs, entr, dir);
		entr = readdir(dirp);
	}
	closedir(dirp);
	return (0);
}
