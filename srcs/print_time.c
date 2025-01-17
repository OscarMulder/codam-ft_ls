/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_time.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:35:22 by omulder        #+#    #+#                */
/*   Updated: 2019/03/26 17:42:03 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_time(t_filelst *ptr)
{
	static time_t	cur;
	time_t			past;
	time_t			future;
	time_t			file;
	char			**timearr;

	file = ptr->stat->st_mtimespec.tv_sec;
	if (cur == 0)
		cur = time(NULL);
	past = cur - SIXMONTHS;
	future = cur + SIXMONTHS;
	timearr = ft_strsplit(ctime(&file), ' ');
	if (cur == -1 || (file > past && file <= cur))
	{
		ft_printf("%3.3s ", timearr[MONTH]);
		ft_printf("%2.2s ", timearr[DAY]);
		ft_printf("%5.5s ", timearr[TIME]);
	}
	else
	{
		ft_printf("%3.3s ", timearr[MONTH]);
		ft_printf("%2.2s  ", timearr[DAY]);
		ft_printf("%d ", ft_atoi(timearr[YEAR]));
	}
	ft_strarrdel(timearr);
}
