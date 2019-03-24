/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_args.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 13:44:53 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 16:57:34 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		exit_usage(char **argv, char c)
{
	ft_dprintf(2, "%s: illegal option -- %c\n", argv[0], c);
	ft_dprintf(2, "usage: ft_ls [-alrtR1] [file ...]\n");
	exit(ERROR);
}

static t_args	set_display(t_args args, int l, int one)
{
	args.one = one;
	args.l = l;
	return (args);
}

t_args			set_args(t_args args, char *str, char **argv)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'l')
			args = set_display(args, 1, 0);
		else if (str[i] == 'R')
			args.rec = 1;
		else if (str[i] == 'a')
			args.a = 1;
		else if (str[i] == 'r')
			args.r = 1;
		else if (str[i] == 't')
			args.t = 1;
		else if (str[i] == '1')
			args = set_display(args, 0, 1);
		else
			exit_usage(argv, str[i]);
		i++;
	}
	return (args);
}
