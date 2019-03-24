/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_find_print.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:18:57 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 14:18:59 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	file_find_print(t_filelst *filelst, t_args args, char *file)
{
	t_filelst	*single;

	while (filelst != NULL)
	{
		if (ft_strcmp(file, filelst->linkname) == 0)
		{
			single = filelst;
			single->next = NULL;
			break ;
		}
		filelst = filelst->next;
	}
	filelst_sort_print(&single, args);
}
