/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filelst_print_noflag.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:02:53 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 13:41:48 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

static int			get_row(int n, int width, int length)
{
	int row;

	if (n == 0 || width == 0 || length == 0)
		return (1);
	if (width / length == 0)
		return (1);
	row = (n / (width / length));
	if ((n % (width / length)) != 0)
		row++;
	return (row);
}

static int			get_termwidth(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

static t_filelst	*set_ptr(t_filelst *ptr, t_filelst *filelst, int l, int row)
{
	int	j;

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
			break ;
		}
		j++;
	}
	return (ptr);
}

static t_print		init_vars(t_filelst *filelst)
{
	t_print		a;

	a.length = filelst_lenname(filelst, 0) + 1;
	a.coli = 1;
	a.total = filelst_count(filelst);
	a.row = get_row(a.total, get_termwidth(), a.length);
	if (a.row == 0)
		a.col = 1;
	else
		a.col = a.total / a.row;
	a.left = a.total % a.row;
	a.printed = 0;
	a.extra = 0;
	return (a);
}

void				filelst_print_noflag(t_filelst *filelst)
{
	t_filelst	*ptr;
	t_print		a;

	ptr = filelst;
	a = init_vars(filelst);
	while (a.printed < a.total)
	{
		if (a.coli == a.col && a.extra == (a.row - 1))
			ft_printf("%s\n", ptr->filename);
		else if (a.coli == (a.col + (a.left != 0)))
		{
			ft_printf("%s\n", ptr->filename);
			if (a.left != 0)
				a.left--;
			a.coli = 0;
			a.extra++;
		}
		else
			ft_printf("%-*s", a.length, ptr->filename);
		a.coli++;
		ptr = set_ptr(ptr, filelst, a.extra, a.row);
		a.printed++;
	}
}
