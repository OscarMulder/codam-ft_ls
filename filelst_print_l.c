/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_print_l.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/17 13:05:48 by omulder        #+#    #+#                */
/*   Updated: 2019/03/23 20:27:17 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/xattr.h>
#include <time.h>
#include <sys/types.h>
#include <sys/acl.h>
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
	if ((st_mode & S_IXUSR) && (st_mode & S_ISUID))
		perm[3] = 's';
	else if ((st_mode & S_ISUID))
		perm[3] = 'S';
	else if ((st_mode & S_IXUSR))
		perm[3] = 'x';
	if ((st_mode & S_IRGRP))
		perm[4] = 'r';
	if ((st_mode & S_IWGRP))
		perm[5] = 'w';
	if ((st_mode & S_IXGRP) && (st_mode & S_ISGID))
		perm[6] = 's';
	else if ((st_mode & S_ISGID))
		perm[6] = 'S';
	else if ((st_mode & S_IXGRP))
		perm[6] = 'x';
	if ((st_mode & S_IROTH))
		perm[7] = 'r';
	if ((st_mode & S_IWOTH))
		perm[8] = 'w';
	if ((st_mode & S_ISVTX) && (st_mode & S_IXOTH))
		perm[9] = 't';
	else if ((st_mode & S_ISVTX))
		perm[9] = 'T';
	else if ((st_mode & S_IXOTH))
		perm[9] = 'x';
	return (perm);
}

void	print_time(t_filelst *ptr)
{
	time_t	cur;
	time_t	past;
	time_t	future;
	time_t	file;
	char	**timearr;

	file = ptr->stat->st_mtimespec.tv_sec;
	cur = time(NULL);
	past = cur - SIXMONTHS;
	future = cur + SIXMONTHS;
	timearr = ft_strsplit(ctime(&file), ' ');
	if (cur == -1 || (file > past && file < future))
	{
		ft_printf("%3.3s ", timearr[MONTH]);
		ft_printf("%2.2s ", timearr[DAY]);
		ft_printf("%5.5s ", timearr[TIME]);
	}
	else
	{
		ft_printf("%3.3s ", timearr[MONTH]);
		ft_printf("%2.2s  ", timearr[DAY]);
		ft_printf("%d ", ft_atoi(timearr[YEAR]));
	}
}

void	filelst_maximums(t_filelst *ptr, t_max *max)
{
	t_max curr;


	if (ptr->next != NULL)
		filelst_maximums(ptr->next, max);
	curr.link = pf_longlen(ptr->stat->st_nlink);
	curr.username = ft_strlen(file_getusername(ptr->stat->st_uid));
	curr.groupname = ft_strlen(file_getgrname(ptr->stat->st_gid));
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
	if (curr.link > max->link)
		max->link = curr.link;
	if (curr.username > max->username)
		max->username = curr.username;
	if (curr.groupname > max->groupname)
		max->groupname = curr.groupname;
	if (curr.size > max->size)
		max->size = curr.size;
}

void	filelst_print_l(t_filelst *filelst)
{
	t_filelst	*ptr;
	t_max		*max;
	acl_t		acl;
	ssize_t		ret;
	char		*perm;

	max = (t_max*)malloc(sizeof(t_max));
	max->link = 0;
	max->username = 0;
	max->groupname = 0;
	max->size = 0;
	filelst_maximums(filelst, max);
	if (max->size > (max->major + max->minor + 2))
		max->major = (max->size - (max->major + max->minor + 2));
	ptr = filelst;
	while (ptr != NULL)
	{
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
		ft_printf("%*d ", max->link, ptr->stat->st_nlink);
		ft_printf("%-*s  %-*s ", max->username, file_getusername(ptr->stat->st_uid), max->groupname, file_getgrname(ptr->stat->st_gid));
		if (ptr->spec)
			ft_printf("%*u, %*u ", max->major, major(ptr->stat->st_rdev), max->minor, minor(ptr->stat->st_rdev));
		else
			ft_printf("%*u ", max->size, ptr->stat->st_size);
		print_time(ptr);
		ft_printf("%s\n", ptr->linkname);
		ptr = ptr->next;
	}
}
