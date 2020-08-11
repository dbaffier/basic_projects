/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:54:18 by dbaffier          #+#    #+#             */
/*   Updated: 2020/01/03 14:23:39 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_err(int err)
{
	(void)err;
	write(2, "Usage : ./lug <filename>\n", 25);
	return (1);
}

int			main(int ac, char **av)
{
	int		err;
	t_lug	lug;

	if (ac < 2)
		return (ft_err(ERR_ARG));
	ft_memset(&lug, 0, sizeof(t_lug));
	if ((err = parse(&lug, av[1])) > 0)
		return (err);
	if ((err = ft_init(&lug, av[1])) > 0)
		return (err);
	fdf(&lug);
	mlx_hook(lug.window, 2, 0, keyhook, &lug);
	while (mlx_loop(lug.mlx_ptr))
		;
	return (0);
}
