/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_total_blocks.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/17 13:13:56 by omulder        #+#    #+#                */
/*   Updated: 2019/03/17 13:22:00 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		filelst_total_blocks(t_filelst *filelst)
{
	if (filelst != NULL)
		return (filelst->stat->st_blocks + filelst_total_blocks(filelst->next));
	return (0);
}
