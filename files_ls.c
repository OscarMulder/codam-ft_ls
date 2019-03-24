/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   files_ls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:11:22 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:11:25 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	files_ls(t_args args, char **files, int *ix)
{
	if (ix[FILES] > 0)
		ix[RET] += ls_file(args, files, (size_t)ix[FILES]);
	if (ix[FILES] > 0 && ix[DIRI] > 0 && ix[RET] != ix[FILES])
		ft_printf("\n");
}
