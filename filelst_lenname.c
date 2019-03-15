/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_lenname.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:02:38 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 17:02:41 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		filelst_lenname(t_filelst *filelst, int length)
{
	int len;

	if (filelst != NULL)
	{
		len = ft_strlen(filelst->entr->d_name);
		if (length > len)
			len = length;
		if (filelst->next != NULL)
			return (filelst_lenname(filelst->next, len));
		return (len);
	}
	return (length);
}
