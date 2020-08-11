/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:39:59 by dbaffier          #+#    #+#             */
/*   Updated: 2020/01/03 14:20:16 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int				ft_init(t_lug *lug, char *name)
{
	int		ret[3];
	int		size;

	if (!(lug->draw = ft_memalloc(sizeof(t_draw))))
		return (ERR_MALLOC);
	lug->mlx_ptr = mlx_init();
	lug->progname = name;
	size = lug->cord->size;
	lug->zoom = ft_min(WIDTH / size / 2, HEIGHT / lug->list_size / 2);
	lug->window = mlx_new_window(lug->mlx_ptr, WIDTH, HEIGHT, lug->progname);
	lug->image = mlx_new_image(lug->mlx_ptr, WIDTH, HEIGHT);
	lug->x_off = 0;
	lug->y_off = 0;
	ft_memset(&ret, 0, sizeof(int) * 3);
	lug->str = mlx_get_data_addr(lug->image, &ret[0], &ret[1], &ret[2]);
	return (0);
}
