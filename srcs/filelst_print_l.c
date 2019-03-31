/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_print_l.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/17 13:05:48 by omulder        #+#    #+#                */
/*   Updated: 2019/03/26 17:30:18 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_max(t_filelst *filelst, t_max *max)
{
	max->link = 0;
	max->username = 0;
	max->groupname = 0;
	max->size = 0;
	max->major = 0;
	max->minor = 0;
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
	ft_strdel(&perm);
	free(acl);
}

static void	print_user_group(t_filelst *ptr, t_max *max)
{
	char		*usern;
	char		*groupname;
	int			isstr;

	isstr = 0;
	usern = file_getusername(ptr->stat->st_uid);
	if (usern == NULL)
		ft_printf("%-*d  ", max->username, ptr->stat->st_uid);
	else
		ft_printf("%-*s  ", max->username, usern);
	isstr = 0;
	groupname = file_getgrname(ptr->stat->st_gid);
	if (groupname == NULL)
		ft_printf("%-*d ", max->groupname, ptr->stat->st_gid);
	else
		ft_printf("%-*s ", max->groupname, groupname);
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
		print_user_group(ptr, max);
		if (ptr->spec)
			ft_printf("%*u,%*u ", 4, major(ptr->stat->st_rdev),
			4, minor(ptr->stat->st_rdev));
		else
			ft_printf("%*u ", max->size, ptr->stat->st_size);
		print_time(ptr);
		ft_printf("%s\n", ptr->linkname);
		ptr = ptr->next;
	}
	free(max);
}
