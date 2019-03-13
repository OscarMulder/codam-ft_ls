/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:26:37 by omulder        #+#    #+#                */
/*   Updated: 2019/02/02 13:37:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dstlen;

	i = 0;
	j = 0;
	while (j < (size) && dst[j] != '\0')
		j++;
	dstlen = j;
	while (size != 0 && (j + i) < (size - 1) && src[i] != '\0')
	{
		dst[(j + i)] = src[i];
		i++;
	}
	if ((j + i) != size)
		dst[(j + i)] = '\0';
	return (dstlen + ft_strlen(src));
}
