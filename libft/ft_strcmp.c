/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 14:47:48 by omulder       #+#    #+#                 */
/*   Updated: 2019/01/09 14:47:50 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	if ((*s1 != '\0' && *s2 != '\0') && (*s1 == *s2))
		return (ft_strcmp(&s1[1], &s2[1]));
	return ((unsigned char)s1[0] - (unsigned char)s2[0]);
}
