/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_dot.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 15:25:00 by omulder        #+#    #+#                */
/*   Updated: 2019/03/13 16:21:15 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_dot(t_fmt copy)
{
	if (copy.prec != 0 || copy.HASH)
		return (pf_putchar('.'));
	return (0);
}
