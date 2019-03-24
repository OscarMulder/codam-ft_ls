/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_getgrname.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:34:21 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:34:23 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*file_getgrname(gid_t gid)
{
	struct group *grp;

	grp = getgrgid(gid);
	return (grp->gr_name);
}
