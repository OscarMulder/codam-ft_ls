/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_perm_str.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:35:04 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:35:09 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	filelst_perm_str2(mode_t st_mode, char *perm)
{
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
}

char		*filelst_perm_str(mode_t st_mode)
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
	filelst_perm_str2(st_mode, perm);
	return (perm);
}
