/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_args.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 13:45:27 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 13:45:40 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args	init_args(void)
{
	t_args args;

	args.l = 0;
	args.R = 0;
	args.a = 0;
	args.r = 0;
	args.t = 0;
	return (args);
}
