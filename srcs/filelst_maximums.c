/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_maximums.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:35:42 by omulder        #+#    #+#                */
/*   Updated: 2019/03/31 17:04:50 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	set_major_minor(t_filelst *ptr, t_max curr, t_max *max)
{
	if (S_ISCHR(ptr->stat->st_mode) || S_ISBLK(ptr->stat->st_mode))
	{
		ptr->spec = 1;
		curr.size = 9;
	}
	else
		curr.size = pf_longlen(ptr->stat->st_size) + 1;
	if (curr.size > max->size)
		max->size = curr.size;
}

void		filelst_maximums(t_filelst *ptr, t_max *max)
{
	t_max	curr;
	char	*un;
	char	*gn;

	if (ptr->next != NULL)
		filelst_maximums(ptr->next, max);
	curr.link = pf_longlen(ptr->stat->st_nlink);
	un = file_getusername(ptr->stat->st_uid);
	if (un == NULL)
		curr.username = pf_longlen(ptr->stat->st_uid);
	else
		curr.username = ft_strlen(un);
	gn = file_getgrname(ptr->stat->st_gid);
	if (gn == NULL)
		curr.groupname = pf_longlen(ptr->stat->st_gid);
	else
		curr.groupname = ft_strlen(gn);
	set_major_minor(ptr, curr, max);
	if (curr.link > max->link)
		max->link = curr.link;
	if (curr.username > max->username)
		max->username = curr.username;
	if (curr.groupname > max->groupname)
		max->groupname = curr.groupname;
}
