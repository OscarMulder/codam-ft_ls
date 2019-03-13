/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 15:17:23 by omulder        #+#    #+#                */
/*   Updated: 2019/02/02 12:17:53 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;
	size_t			i;

	ptrdst = (unsigned char*)dst;
	ptrsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ptrdst[i] = (unsigned char)ptrsrc[i];
		if (ptrsrc[i] == (unsigned char)c)
			return (&ptrdst[i + 1]);
		i++;
	}
	return (NULL);
}
