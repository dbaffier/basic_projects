/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:49:05 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/19 01:39:33 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	int				i;
	t_dirs			*dirs;
	t_fg			flags;

	(void)ac;
	flags = 0;
	i = flag_handler(av + 1, &flags);
	dirs = dir_handler(av + i, &flags);
	print_handling(dirs, &flags);
	memory_handler(dirs, DIRS_MEM, &flags);
	return (0);
}
