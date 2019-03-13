/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:03:40 by omulder        #+#    #+#                */
/*   Updated: 2019/02/02 12:28:11 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	skip;
	size_t	len;

	skip = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strnew(1));
	len--;
	while ((s[skip] == ' ' || s[skip] == '\t' || s[skip] == '\n') && skip < len)
		skip++;
	if (skip == len)
		return (ft_strnew(1));
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > 0)
		len--;
	return (ft_strsub(s, skip, (len - skip + 1)));
}
