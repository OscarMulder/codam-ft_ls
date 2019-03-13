/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 10:57:34 by omulder        #+#    #+#                */
/*   Updated: 2019/02/02 12:26:40 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		k = 0;
		while ((i + k) < len && haystack[i + k] == needle[j])
		{
			j++;
			k++;
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
