/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_to_arr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:10:50 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:10:51 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_to_arr(char **dir, char **files, char **argv, int *ix)
{
	if (is_dir(argv[ix[LOOP]], ix[L]))
		ix[DIRI] = add_dir(dir, argv[ix[LOOP]], ix[DIRI]);
	else
		ix[FILES] = add_files(files, argv[ix[LOOP]], ix[FILES]);
}
