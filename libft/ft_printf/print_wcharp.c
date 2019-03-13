/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_wcharp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 11:44:08 by omulder        #+#    #+#                */
/*   Updated: 2019/03/13 16:25:13 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_padding(t_fmt fmt, int slen)
{
	if (!fmt.MIN && (!fmt.ZERO || !(fmt.prec == -1 || fmt.prec == 0)))
		print_padding(' ', (fmt.width - slen));
	if (!fmt.MIN && fmt.ZERO)
		print_padding('0', (fmt.width - slen));
}

int				print_wcharp(t_fmt fmt, wchar_t *str)
{
	int	slen;

	if (str)
		slen = pf_wstrlen(str, fmt.prec);
	else
		slen = pf_wstrlen(L"(null)", fmt.prec);
	if (fmt.prec != -1 && fmt.prec < slen)
		slen = fmt.prec;
	put_padding(fmt, slen);
	if (str)
	{
		if (fmt.prec == -1)
			pf_putwstr(str);
		else
			pf_putnwstr(str, fmt.prec);
	}
	else if (!fmt.ZERO)
		pf_putwstr(L"(null)");
	if (fmt.MIN)
		print_padding(' ', (fmt.width - slen));
	if (fmt.width > slen)
		slen = fmt.width;
	return (slen);
}
