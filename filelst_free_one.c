/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_free_one.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 12:41:58 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 13:16:07 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_free_one(t_filelst **filelst)
{
	if (filelst != NULL && (*filelst) != NULL)
	{
		ft_strdel(&(*filelst)->path);
		free((*filelst)->stat);
		(*filelst)->stat = NULL;
		if ((*filelst)->linkname != (*filelst)->filename)
			ft_strdel(&(*filelst)->linkname);
		ft_strdel(&(*filelst)->filename);
		(*filelst)->next = NULL;
		free((*filelst));
		(*filelst) = NULL;
	}
}
