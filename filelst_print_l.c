/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_print_l.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/17 13:05:48 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:43:23 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_max(t_filelst *filelst, t_max *max)
{
	max->link = 0;
	max->username = 0;
	max->groupname = 0;
	max->size = 0;
	filelst_maximums(filelst, max);
	if (max->size > (max->major + max->minor + 2))
		max->major = (max->size - (max->major + max->minor + 2));
}

static void	print_perms(t_filelst *ptr)
{
	acl_t		acl;
	ssize_t		ret;
	char		*perm;

	perm = filelst_perm_str(ptr->stat->st_mode);
	ft_printf("%-*s", 10, perm);
	ret = listxattr(ptr->path, NULL, 0, XATTR_NOFOLLOW);
	acl = NULL;
	acl = acl_get_link_np(ptr->path, ACL_TYPE_EXTENDED);
	if (ret != 0 && ret != -1)
		ft_printf("@ ");
	else if (acl != NULL)
		ft_printf("+ ");
	else
		ft_printf("  ");
}

void		filelst_print_l(t_filelst *filelst)
{
	t_filelst	*ptr;
	t_max		*max;

	max = (t_max*)malloc(sizeof(t_max));
	init_max(filelst, max);
	ptr = filelst;
	while (ptr != NULL)
	{
		print_perms(ptr);
		ft_printf("%*d ", max->link, ptr->stat->st_nlink);
		ft_printf("%-*s  %-*s ", max->username,
		file_getusername(ptr->stat->st_uid), max->groupname,
		file_getgrname(ptr->stat->st_gid));
		if (ptr->spec)
			ft_printf("%*u, %*u ", max->major, major(ptr->stat->st_rdev),
			max->minor, minor(ptr->stat->st_rdev));
		else
			ft_printf("%*u ", max->size, ptr->stat->st_size);
		print_time(ptr);
		ft_printf("%s\n", ptr->linkname);
		ptr = ptr->next;
	}
	free(max);
}
