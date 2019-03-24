/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_sort_tr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:23:05 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 17:15:27 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_vars(t_filelst *ptr, t_filelst *prev, t_filelst **sptr,
t_filelst **prevsmal)
{
	*prevsmal = prev;
	*sptr = ptr;
}

void			filelst_sort_tr(t_filelst **filelst)
{
	t_filelst	*ptr;
	t_filelst	*prev;
	t_filelst	*sptr;
	t_filelst	*prevsmal;

	sptr = *filelst;
	ptr = sptr->next;
	prev = *filelst;
	while (ptr != NULL)
	{
		if (ptr->stat->st_mtimespec.tv_sec < sptr->stat->st_mtimespec.tv_sec)
			set_vars(ptr, prev, &sptr, &prevsmal);
		else if (ptr->stat->st_mtimespec.tv_sec ==
		sptr->stat->st_mtimespec.tv_sec)
		{
			if (ft_strcmp(sptr->filename, ptr->filename) < 0)
				set_vars(ptr, prev, &sptr, &prevsmal);
		}
		prev = ptr;
		ptr = ptr->next;
	}
	if (sptr != *filelst)
		filelst_swap(filelst, sptr, prevsmal);
	if ((*filelst)->next != NULL)
		filelst_sort_tr(&(*filelst)->next);
}
