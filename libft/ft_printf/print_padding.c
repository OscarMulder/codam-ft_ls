/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_padding.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 15:50:37 by omulder        #+#    #+#                */
/*   Updated: 2019/03/13 16:21:15 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_padding(char c, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		pf_putchar(c);
		i++;
	}
	return (size);
}
