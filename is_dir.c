/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_dir.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:08:20 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 14:08:39 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
