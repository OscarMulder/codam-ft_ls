/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:09:48 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 14:09:52 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*make_path(char *dir, struct dirent *entr)
{
	char *temp;
	char *path;

	temp = ft_strjoin(dir, "/");
	path = ft_strjoin(temp, entr->d_name);
	ft_strdel(&temp);
	return (path);
}
