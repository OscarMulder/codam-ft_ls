/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrsort_r.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 13:49:55 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:55:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrsort_r(char **arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (arr[i] != 0)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(arr[j], temp) < 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
		i++;
	}
}
