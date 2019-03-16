/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:04:10 by omulder        #+#    #+#                */
/*   Updated: 2019/03/16 19:19:44 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + ft_lstcount(lst->next));
}
