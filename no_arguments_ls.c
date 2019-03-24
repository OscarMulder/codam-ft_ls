/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_arguments_ls.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:11:06 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:11:08 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	no_arguments_ls(t_args args, int *ix)
{
	if (ix[DIRI] == 0 && ix[FILES] == 0)
		ix[RET] = ls(args, ".");
}
