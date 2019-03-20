/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_sort_t.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:06:03 by omulder        #+#    #+#                */
/*   Updated: 2019/03/20 11:22:00 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_sort_t(t_filelst **filelst)
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
		if (ptr->stat->st_mtimespec.tv_sec > smallest->stat->st_mtimespec.tv_sec)
		{
			prevsmal = prev;
			smallest = ptr;
		}
		else if (ptr->stat->st_mtimespec.tv_sec == smallest->stat->st_mtimespec.tv_sec)
		{
			if (ft_strcmp(smallest->filename, ptr->filename) > 0)
			{
				prevsmal = prev;
				smallest = ptr;
			}
		}
		prev = ptr;
		ptr = ptr->next;
	}
	if (smallest != *filelst)
		filelst_swap(filelst, smallest, prevsmal);
	if ((*filelst)->next != NULL)
		filelst_sort_t(&(*filelst)->next);
}
