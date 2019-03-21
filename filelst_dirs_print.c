/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_dirs_print.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 10:08:57 by omulder        #+#    #+#                */
/*   Updated: 2019/03/21 10:09:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_dirs_print(t_filelst *dirs, t_args args)
{
	while (args.R && dirs != NULL)
	{
		ft_printf("\n%s:\n", dirs->path);
		ls(args, dirs->path);
		dirs = dirs->next;
	}
}
