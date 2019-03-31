/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 11:22:19 by omulder        #+#    #+#                */
/*   Updated: 2019/03/20 11:22:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_swap(t_filelst **flst, t_filelst *smal, t_filelst *prev)
{
	prev->next = smal->next;
	smal->next = *flst;
	*flst = smal;
}
