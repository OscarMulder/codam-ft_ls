/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_getmode.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:34:37 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:34:39 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
