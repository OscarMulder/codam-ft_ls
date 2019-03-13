/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:51:49 by omulder        #+#    #+#                */
/*   Updated: 2019/02/01 11:56:09 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	build_array(char const *s, char c, char **arr, unsigned int strs)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			k = 0;
			strs++;
			arr[j] = ft_strnew(ft_strdlen(&s[i], c) + 1);
			while (s[i] != c && s[i] != '\0')
			{
				arr[j][k] = s[i];
				k++;
				i++;
			}
			j++;
			i--;
		}
		i++;
	}
	arr[j] = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	char			**arr;
	unsigned int	strs;

	if (s == NULL)
		return (NULL);
	strs = ft_strdcount(s, c);
	arr = (char**)malloc(sizeof(char*) * (strs + 1));
	if (arr == NULL)
		return (NULL);
	build_array(s, c, arr, strs);
	return (arr);
}
