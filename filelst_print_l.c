/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_print_l.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/17 13:05:48 by omulder        #+#    #+#                */
/*   Updated: 2019/03/20 15:03:59 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/xattr.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>

char	*file_getusername(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	return (pwd->pw_name);
}

char	*file_getgrname(gid_t gid)
{
	struct group *grp;

	grp = getgrgid(gid);
	return (grp->gr_name);
}

char	file_getmode(mode_t st_mode)
{
	if (S_ISBLK(st_mode))
		return ('b');
	if (S_ISCHR(st_mode))
		return ('c');
	if (S_ISDIR(st_mode))
		return ('d');
	if (S_ISLNK(st_mode))
		return ('l');
	if (S_ISSOCK(st_mode))
		return ('s');
	if (S_ISFIFO(st_mode))
		return ('p');
	if (S_ISREG(st_mode))
		return ('-');
	return ('-');
}

char	*filelst_perm_str(mode_t st_mode)
{
	char	*perm;

	perm = ft_strdup("----------");
	perm[0] = file_getmode(st_mode);
	if ((st_mode & S_IRUSR))
		perm[1] = 'r';
	if ((st_mode & S_IWUSR))
		perm[2] = 'w';
	if ((st_mode & S_IXUSR))
		perm[3] = 'x'; // can be more
	if ((st_mode & S_IRGRP))
		perm[4] = 'r';
	if ((st_mode & S_IWGRP))
		perm[5] = 'w';
	if ((st_mode & S_IXGRP))
		perm[6] = 'x'; // can be more
	if ((st_mode & S_IROTH))
		perm[7] = 'r';
	if ((st_mode & S_IWOTH))
		perm[8] = 'w';
	if ((st_mode & S_IXOTH))
		perm[9] = 'x'; // can be more
	return (perm);
}

void	filelst_maximums(t_filelst *ptr, t_max *max)
{
	int link;
	int username;
	int groupname;
	int	size;

	if (ptr->next != NULL)
		filelst_maximums(ptr->next, max);
	link = pf_longlen(ptr->stat->st_nlink);
	username = ft_strlen(file_getusername(ptr->stat->st_uid));
	groupname = ft_strlen(file_getgrname(ptr->stat->st_gid));
	size = pf_longlen(ptr->stat->st_size) + 1;
	if (link > max->link)
		max->link = link;
	if (username > max->username)
		max->username = username;
	if (groupname > max->groupname)
		max->groupname = groupname;
	if (size > max->size)
		max->size = size;
}

void	filelst_print_l(t_filelst *filelst)
{
	t_filelst	*ptr;
	t_max		*max;

	max = (t_max*)malloc(sizeof(t_max));
	max->link = 0;
	max->username = 0;
	max->groupname = 0;
	max->size = 0;
	filelst_maximums(filelst, max);
	ptr = filelst;
	ft_printf("total %d\n", filelst_total_blocks(filelst));
	while (ptr != NULL)
	{
		ft_printf("%-*s", 10, filelst_perm_str(ptr->stat->st_mode));
		if (listxattr(ptr->path, NULL, 0, 0) != 0)
			ft_printf("@ ");
		else
			ft_printf("  ");
		ft_printf("%*d ", max->link, ptr->stat->st_nlink);
		ft_printf("%*s  %*s ", max->username, file_getusername(ptr->stat->st_uid), max->groupname, file_getgrname(ptr->stat->st_gid));
		ft_printf("%*d ", max->size, ptr->stat->st_size);
		ft_printf("%.3s ", &(ctime(&ptr->stat->st_mtimespec.tv_sec))[4]);
		ft_printf("%.2s ", &(ctime(&ptr->stat->st_mtimespec.tv_sec))[8]);
		ft_printf("%.5s ", &(ctime(&ptr->stat->st_mtimespec.tv_sec))[11]);
		//ft_printf("%s %d %d:%d ", "Mar", 17, 13, 42);
		if (S_ISLNK(ptr->stat->st_mode))
			ft_printf("%s\n", ptr->linkname);
		else
			ft_printf("%s\n", ptr->filename);
		ptr = ptr->next;
	}
}
