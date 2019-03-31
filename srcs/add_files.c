/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_files.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:06:42 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:06:50 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_files(char **files, char *str, int k)
{
	files[k] = ft_strdup(str);
	k++;
	return (k);
}
