/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:09:48 by omulder        #+#    #+#                */
/*   Updated: 2019/03/25 14:50:18 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*make_path(char *dir, struct dirent *entr)
{
	char *temp;
	char *path;

	if (ft_strcmp(dir, "/") != 0)
		temp = ft_strjoin(dir, "/");
	else
		temp = ft_strdup(dir);
	path = ft_strjoin(temp, entr->d_name);
	ft_strdel(&temp);
	return (path);
}
