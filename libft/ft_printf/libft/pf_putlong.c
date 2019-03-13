/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putlong.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 14:01:23 by omulder        #+#    #+#                */
/*   Updated: 2019/03/13 16:23:19 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putlong(long long n)
{
	if (n < 0)
	{
		if (n < -9)
			pf_putlong((n / 10) * -1);
		pf_putchar(-(n % 10) + '0');
	}
	else
	{
		if (n > 9)
			pf_putlong(n / 10);
		pf_putchar((n % 10) + '0');
	}
}
