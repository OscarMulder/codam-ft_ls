/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_print.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/17 12:58:43 by omulder        #+#    #+#                */
/*   Updated: 2019/03/21 15:20:22 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	filelst_print(t_filelst *filelst, t_args args)
{
	if (args.one)
		filelst_print_one(filelst);
	else if (args.l)
		filelst_print_l(filelst);
	else
		filelst_print_noflag(filelst);
}
