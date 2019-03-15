/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:04:10 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 21:00:54 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		filelst_count(t_filelst *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + ft_lstcount(lst->next));
}
