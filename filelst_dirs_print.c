/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_dirs_print.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 10:08:57 by omulder        #+#    #+#                */
/*   Updated: 2019/03/23 17:30:14 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		filelst_dirs_print(t_filelst *dirs, t_args args)
{
	int ret;

	ret = 0;
	while (args.R && dirs != NULL)
	{
		ft_printf("\n%s:\n", dirs->path);
		if (ls(args, dirs->path))
			ret = 1;
		dirs = dirs->next;
	}
	return (ret);
}
