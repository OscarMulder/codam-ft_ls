/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/13 19:39:43 by omulder        #+#    #+#                */
/*   Updated: 2019/03/24 15:12:21 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_args	args;
	char	**dir;
	char	**files;
	int		*ix;

	ix = (int*)malloc(sizeof(int) * 5);
	dir = (char**)ft_memalloc(sizeof(char*) * (argc + 1));
	files = (char**)ft_memalloc(sizeof(char*) * argc);
	ix[LOOP] = get_args(&args, argv, argc);
	init_ix(ix, args.l);
	while (ix[LOOP] < argc)
	{
		if (ft_strcmp(argv[ix[LOOP]], "") == 0)
			return (error_nofile(dir, files));
		add_to_arr(dir, files, argv, ix);
		ix[LOOP]++;
	}
	ix[LOOP] = 0;
	sort_arrs(args, ix, dir, files);
	start_ls(args, dir, files, ix);
	return (end_ls(ix));
}
