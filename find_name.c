/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_name.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:19:41 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 14:19:45 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*find_name(char *file)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (file[size] != '\0')
		size++;
	i = size;
	while (i >= 0 && file[i] != '/')
		i--;
	if (i >= 0)
		return (ft_strsub(file, (i + 1), (size - i)));
	return (ft_strdup(file));
}
