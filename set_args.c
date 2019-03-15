/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_args.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 13:44:53 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 20:11:26 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args	set_args(t_args args, char *str)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'l')
			args.l = 1;
		if (str[i] == 'R')
			args.R = 1;
		if (str[i] == 'a')
			args.a = 1;
		if (str[i] == 'r')
			args.r = 1;
		if (str[i] == 't')
			args.t = 1;
		i++;
	}
	return (args);
}
