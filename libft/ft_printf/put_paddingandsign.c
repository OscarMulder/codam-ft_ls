/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_paddingandsign.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:07:28 by omulder        #+#    #+#                */
/*   Updated: 2019/03/13 16:21:15 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_paddingandsign(t_fmt fmt, long long num, int ilen)
{
	if (!fmt.MIN && (!fmt.ZERO || fmt.prec != -1))
		print_padding(' ', (fmt.width - ilen));
	if (num >= 0 && fmt.SPACE && !fmt.PLUS)
		pf_putchar(' ');
	if (num == 0 && fmt.prec == 0 && fmt.width != -1)
		pf_putchar(' ');
	if (num >= 0 && fmt.PLUS == 1)
		pf_putchar('+');
	if (num < 0 || fmt.PLUS == -1)
		pf_putchar('-');
	if (!fmt.MIN && fmt.ZERO && fmt.prec == -1)
		print_padding('0', (fmt.width - ilen));
}
