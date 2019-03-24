/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_dir.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:20:01 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 14:20:03 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*find_dir(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	while (i >= 0 && file[i] != '/')
		i--;
	if (i >= 0)
		return (ft_strsub(file, 0, i + 1));
	return (ft_strdup("."));
}
