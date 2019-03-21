/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_sort_n.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:00:02 by omulder        #+#    #+#                */
/*   Updated: 2019/03/21 10:02:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_sort_n(t_filelst **filelst)
{
	t_filelst	*ptr;
	t_filelst	*prev;
	t_filelst	*smallest;
	t_filelst	*prevsmal;

	smallest = *filelst;
	ptr = smallest->next;
	prev = *filelst;
	while (ptr != NULL)
	{
		if (ft_strcmp(smallest->filename, ptr->filename) > 0)
		{
			prevsmal = prev;
			smallest = ptr;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	if (smallest != *filelst)
		filelst_swap(filelst, smallest, prevsmal);
	if ((*filelst)->next != NULL)
		filelst_sort_n(&(*filelst)->next);
}
