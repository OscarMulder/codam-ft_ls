/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_nofile.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:09:19 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:09:23 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_nofile(char **dir, char **files)
{
	ft_dprintf(2, "%s: %s: No such file or directory\n", "ft_ls", "fts_open");
	ft_strarrdel(dir);
	ft_strarrdel(files);
	return (1);
}
