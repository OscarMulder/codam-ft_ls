/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddback.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:05:54 by omulder        #+#    #+#                */
/*   Updated: 2019/02/02 17:11:35 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	if ((*alst)->next != NULL)
		ft_lstaddback(&(*alst)->next, new);
	else
		(*alst)->next = new;
}
