/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_ls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:11:57 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:12:00 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	start_ls(t_args args, char **dir, char **files, int *ix)
{
	no_arguments_ls(args, ix);
	if (ix[RET] == 1)
	{
		ft_strarrdel(dir);
		ft_strarrdel(files);
		return ;
	}
	files_ls(args, files, ix);
	dirs_ls(args, dir, ix);
	ft_strarrdel(dir);
	ft_strarrdel(files);
	if (ix[RET] > 1)
		ix[RET] = 1;
}
