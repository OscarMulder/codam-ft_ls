/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putcharsign.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:07:22 by omulder        #+#    #+#                */
/*   Updated: 2019/03/13 16:21:15 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putcharsign(long long c)
{
	char cs;

	cs = (char)c;
	if (cs < 0)
	{
		if (cs < -9)
			pf_putcharsign((cs / 10) * -1);
		pf_putchar(-(cs % 10) + '0');
	}
	else
	{
		if (cs > 9)
			pf_putcharsign(cs / 10);
		pf_putchar((cs % 10) + '0');
	}
}
