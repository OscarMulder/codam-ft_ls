/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ls.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:15:46 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 14:15:51 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls(t_args args, char *dir)
{
	t_filelst		*filelst;
	t_filelst		*dirs;
	int				ret;

	ret = 0;
	filelst = NULL;
	dirs = NULL;
	if (create_filelsts(&filelst, &dirs, args, dir) == ERROR)
		return (ERROR);
	if ((dirs != NULL || filelst != NULL) && args.l)
		ft_printf("total %d\n", filelst_total_blocks(filelst));
	filelst_sort_print(&filelst, args);
	if (dirs != NULL && dirs->next != NULL)
		filelst_sort(&dirs, args);
	if (filelst_dirs_print(dirs, args))
		ret = 1;
	filelst_free_all(&filelst);
	filelst_free_all(&dirs);
	return (ret);
}
