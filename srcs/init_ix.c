/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ix.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:09:36 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:09:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_ix(int *ix, int l)
{
	ix[DIRI] = 0;
	ix[FILES] = 0;
	ix[RET] = 0;
	ix[L] = l;
}