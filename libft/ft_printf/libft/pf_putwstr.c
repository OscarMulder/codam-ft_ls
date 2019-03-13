/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putwstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 11:39:45 by omulder        #+#    #+#                */
/*   Updated: 2019/03/13 16:24:29 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putwstr(wchar_t const *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		pf_putchar_uni(s[i]);
		i++;
	}
}
