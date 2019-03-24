/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_getusername.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:31:41 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:33:15 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*file_getusername(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	return (pwd->pw_name);
}
