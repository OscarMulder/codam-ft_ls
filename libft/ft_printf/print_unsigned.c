/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_unsigned.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 11:17:53 by omulder        #+#    #+#                */
/*   Updated: 2019/03/13 16:25:03 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	typecast(t_fmt fmt, unsigned long long num)
{
	if (is_uchar(fmt))
		return ((unsigned char)num);
	if (is_ushort(fmt))
		return ((unsigned short)num);
	if (is_uint(fmt))
		return ((unsigned int)num);
	if (is_ulong(fmt))
		return ((unsigned long long)num);
	if (is_voidp(fmt))
		return ((unsigned long long)num);
	return ((unsigned long long)num);
}

static t_fmt				set_prec(t_fmt fmt, unsigned long long n, int ilen)
{
	if (is_voidp(fmt))
		fmt.HASH = 1;
	if (fmt.HASH && is_octal(fmt) && fmt.prec < (ilen + 1))
	{
		if (n == 0)
			ilen--;
		fmt.prec = ilen + 1;
	}
	return (fmt);
}

int							print_unsigned(t_fmt fmt, unsigned long long num)
{
	int ilen;
	int oldprec;

	num = (typecast(fmt, num));
	ilen = pf_ulonglen(num, find_base(fmt));
	oldprec = fmt.prec;
	fmt = set_prec(fmt, num, ilen);
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	put_upaddingandsign(fmt, num, ilen, oldprec);
	if (!fmt.MIN && fmt.prec != -1)
		print_padding('0', (fmt.prec - pf_ulonglen(num, find_base(fmt))));
	if (fmt.MIN && (num != 0 || is_voidp(fmt)))
		print_prehex(fmt);
	if (fmt.MIN && fmt.prec != -1)
		print_padding('0', (fmt.prec - pf_ulonglen(num, find_base(fmt))));
	if (!(fmt.prec == 0 && num == 0))
		pf_putulong_base(num, find_base(fmt), find_case(fmt));
	put_backpadding(fmt, num, ilen);
	return (printed_uchars(fmt, num));
}
