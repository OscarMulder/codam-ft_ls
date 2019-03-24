/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 10:03:38 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 16:57:46 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_sort(t_filelst **filelst, t_args args)
{
	if (*filelst != NULL)
	{
		if (args.r)
		{
			if (args.t)
				filelst_sort_tr(filelst);
			else
				filelst_sort_nr(filelst);
		}
		else
		{
			if (args.t)
				filelst_sort_t(filelst);
			else
				filelst_sort_n(filelst);
		}
	}
}

void	filelst_sort_print(t_filelst **filelst, t_args args)
{
	if (*filelst != NULL)
	{
		if (args.r)
		{
			if (args.t)
				filelst_sort_tr(filelst);
			else
				filelst_sort_nr(filelst);
		}
		else
		{
			if (args.t)
				filelst_sort_t(filelst);
			else
				filelst_sort_n(filelst);
		}
		filelst_print(*filelst, args);
	}
}
