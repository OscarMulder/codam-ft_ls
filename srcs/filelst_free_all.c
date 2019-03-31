/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_free_all.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 12:50:15 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 12:53:43 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_free_all(t_filelst **filelst)
{
	if (filelst != NULL && (*filelst) != NULL)
	{
		if ((*filelst)->next != NULL)
			filelst_free_all(&(*filelst)->next);
		filelst_free_one(filelst);
	}
}
