/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:00:02 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 17:01:17 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_swap(t_filelst **flst, t_filelst *smal, t_filelst *prev)
{
	prev->next = smal->next;
	smal->next = *flst;
	*flst = smal;
}

void	filelst_sort(t_filelst **filelst)
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
		if (ft_strcmp(smallest->entr->d_name, ptr->entr->d_name) > 0)
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
		filelst_sort(&(*filelst)->next);
}
