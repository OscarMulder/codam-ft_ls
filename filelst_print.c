/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_print.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:02:53 by omulder        #+#    #+#                */
/*   Updated: 2019/03/15 21:42:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

void	filelst_print(t_filelst *filelst)
{
	struct winsize w;
	t_filelst	*ptr;
	int		row;
	int		length;
	int		i;
	int		j;
	int		n;
	int		k;
	int		l;
	int 	col;
	int		left;

	ptr = filelst;
	length = filelst_lenname(filelst, 0) + 1;
	ioctl(0, TIOCGWINSZ, &w);
	i = 1;
	n = filelst_count(filelst);
	row = (n / (w.ws_col / length));
	if (n % row != 0)
		row++;
	col = n / row;
	left = n % row;
	k = 0;
	l = 0;
	while (k < n)
	{
		if (i == col && l == (row - 1))
			ft_printf("%s", ptr->entr->d_name);
		else if (i == (col + (left != 0)))
		{
			ft_printf("%s\n", ptr->entr->d_name);
			if (left != 0)
				left--;
			i = 0;
			l++;
		}
		else
			ft_printf("%-*s", length, ptr->entr->d_name);
		i++;
		j = 0;
		while (j < row)
		{
			if (ptr->next != NULL)
				ptr = ptr->next;
			else
			{
				ptr = filelst;
				j = 0;
				while (j < l)
				{
					ptr = ptr->next;
					j++;
				}
				break;
			}
			j++;
		}
		k++;
	}
}
