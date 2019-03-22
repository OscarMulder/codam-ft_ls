/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrsort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 13:15:41 by omulder        #+#    #+#                */
/*   Updated: 2019/03/22 13:29:23 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrsort(char **arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (arr[i] != 0)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(arr[j], temp) > 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
		i++;
	}
}
