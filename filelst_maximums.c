/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_maximums.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:35:42 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:46:22 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_max	set_major_minor(t_filelst *ptr, t_max curr, t_max *max)
{
	curr.major = pf_longlen(major(ptr->stat->st_rdev));
	curr.minor = pf_longlen(minor(ptr->stat->st_rdev));
	if (S_ISCHR(ptr->stat->st_mode) || S_ISBLK(ptr->stat->st_mode))
		ptr->spec = 1;
	if (ptr->spec)
	{
		if (curr.major > max->major)
			max->major = curr.major;
		if (curr.minor > max->minor)
			max->minor = curr.minor;
		curr.size = max->major + max->minor + 2;
	}
	else
		curr.size = pf_longlen(ptr->stat->st_size) + 1;
	return (curr);
}

void			filelst_maximums(t_filelst *ptr, t_max *max)
{
	t_max curr;

	if (ptr->next != NULL)
		filelst_maximums(ptr->next, max);
	curr.link = pf_longlen(ptr->stat->st_nlink);
	curr.username = ft_strlen(file_getusername(ptr->stat->st_uid));
	curr.groupname = ft_strlen(file_getgrname(ptr->stat->st_gid));
	curr = set_major_minor(ptr, curr, max);
	if (curr.link > max->link)
		max->link = curr.link;
	if (curr.username > max->username)
		max->username = curr.username;
	if (curr.groupname > max->groupname)
		max->groupname = curr.groupname;
	if (curr.size > max->size)
		max->size = curr.size;
}
