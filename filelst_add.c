/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_add.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:02:16 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 20:05:41 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_add(t_filelst **filelst, struct dirent *entr, char *dir)
{
	t_filelst	*new;

	new = (t_filelst*)ft_memalloc(sizeof(t_filelst));
	new->path = make_path(dir, entr);
	new->entr = entr;
	new->stat = (struct stat*)ft_memalloc(sizeof(struct stat));
	if (stat(new->path, new->stat) == -1)
		exit(ERROR);
	new->next = *filelst;
	*filelst = new;
}
