/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_arrs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:09:49 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 16:58:22 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_arrs(t_args args, int *ix, char **dir, char **files)
{
	if (args.r && ix[DIRI] > 1)
		ft_strarrsort_r(dir);
	else if (ix[DIRI] > 1)
		ft_strarrsort(dir);
	if (ix[FILES] > 1)
		ft_strarrsort(files);
}
