/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_count.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 20:59:27 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 21:01:13 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		filelst_count(t_filelst *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + filelst_count(lst->next));
}
