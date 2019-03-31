/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_ls.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:12:16 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:12:17 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		end_ls(int *ix)
{
	int ret;

	ret = ix[RET];
	free(ix);
	return (ret);
}