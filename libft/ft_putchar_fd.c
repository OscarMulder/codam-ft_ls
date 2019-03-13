/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:55:11 by omulder        #+#    #+#                */
/*   Updated: 2019/02/06 17:46:50 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(unsigned int c, int fd)
{
		unsigned char b;

	if (c <= 0x7f)
		write(fd, &c, 1);
	else if (c > 0x7f && c <= 0x7FF)
	{
		b = (0xC0 | (c >> 6));
		write(fd, &b, 1);
		b = (0x80 | (c & 0x3F));
		write(fd, &b, 1);
	}
	else if (c > 0x7FF && c <= 0xFFFF)
	{
		b = (0xE0 | (c >> 12));
		write(fd, &b, 1);
		b = (0x80 | ((c >> 6) & 0x3f));
		write(fd, &b, 1);
		b = (0x80 | (c & 0x3F));
		write(fd, &b, 1);
	}
	else if (c > 0xFFFF && c <= 0x001FFFFF)
	{
		b = (0xF0 | (c >> 18));
		write(fd, &b, 1);
		b = (0x80 | ((c >> 12) & 0x3f));
		write(fd, &b, 1);
		b = (0x80 | ((c >> 6) & 0x3f));
		write(fd, &b, 1);
		b = (0x80 | (c & 0x3F));
		write(fd, &b, 1);
	}
}
