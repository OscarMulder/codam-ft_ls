/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_dir.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:06:26 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:25:29 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_dir(char **dir, char *str, int j)
{
	dir[j] = ft_strdup(str);
	j++;
	return (j);
}
