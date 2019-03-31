/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_getusername.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:31:41 by omulder        #+#    #+#                */
/*   Updated: 2019/03/26 17:15:27 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*file_getusername(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		return (NULL);
	return (pwd->pw_name);
}
