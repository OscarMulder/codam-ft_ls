/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dirs_ls.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:11:40 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:11:41 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dirs_ls(t_args args, char **dir, int *ix)
{
	while (ix[LOOP] < ix[DIRI])
	{
		if (ix[DIRI] > 1 || (ix[DIRI] + ix[FILES]) > 1)
			ft_printf("%s:\n", dir[ix[LOOP]]);
		if (ls(args, dir[ix[LOOP]]))
			ix[RET] = 1;
		ix[LOOP]++;
		if (ix[LOOP] < ix[DIRI])
			ft_printf("\n");
	}
}
