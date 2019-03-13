/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:27:57 by omulder        #+#    #+#                */
/*   Updated: 2019/02/01 11:56:09 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strdcount(char const *s, char c)
{
	unsigned int	i;
	unsigned int	strs;

	i = 0;
	strs = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			strs++;
			while (s[i] != c && s[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	return (strs);
}
