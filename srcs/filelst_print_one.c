/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_print_one.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/17 12:55:51 by omulder        #+#    #+#                */
/*   Updated: 2019/03/17 13:21:04 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_print_one(t_filelst *filelst)
{
	if (filelst != NULL)
	{
		if (filelst->next != NULL)
		{
			ft_printf("%s\n", filelst->filename);
			filelst_print_one(filelst->next);
		}
		else
			ft_printf("%s\n", filelst->filename);
	}
}
