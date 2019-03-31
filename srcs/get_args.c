/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_args.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:05:41 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:05:53 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_args(t_args *args, char **argv, int argc)
{
	int i;

	i = 1;
	*args = init_args();
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0' &&
		ft_strcmp(argv[i], "--") != 0)
		{
			*args = set_args(*args, argv[i], argv);
			i++;
		}
		else
		{
			if (ft_strcmp(argv[i], "--") == 0)
				i++;
			break ;
		}
	}
	return (i);
}
