/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:24:49 by mmonier           #+#    #+#             */
/*   Updated: 2020/01/03 14:30:02 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pt		new_p(int x, int y, int z)
{
	t_pt		pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}

static void		gen_next(t_lug *lug, t_pt a, t_pt b)
{
	lug->draw->x1 = a.x;
	lug->draw->y1 = a.y;
	lug->draw->x2 = b.x;
	lug->draw->y2 = b.y;
	bresenham(lug, lug->draw, MLX_BLUE);
}

static void		iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

static t_pt		shift(t_pt p, t_lug *lug)
{
	(void)lug;
	p.x *= lug->zoom;
	p.y *= lug->zoom;
	p.z *= lug->zoom / 1;
	p.x -= (lug->cord->size * lug->zoom) / 2;
	p.y -= (lug->list_size * lug->zoom) / 2;
	rotate_x(&p.y, &p.z, lug->alpha);
	rotate_y(&p.x, &p.z, lug->beta);
	rotate_z(&p.x, &p.y, lug->gamma);
	iso(&p.x, &p.y, p.z);
	p.x += WIDTH / 2 + lug->x_off;
	p.y += (HEIGHT + lug->list_size * lug->zoom) / 2 + lug->y_off;
	return (p);
}

int				fdf(t_lug *lug)
{
	t_p		*p;
	int		x;
	int		y;

	y = 0;
	p = lug->cord;
	while (p)
	{
		x = 0;
		while (x < p->size - 1)
		{
			if (x + 1 < p->size - 1)
				gen_next(lug, shift(new_p(x, y, p->line[x]), lug),
						shift(new_p(x + 1, y, p->line[x + 1]), lug));
			if (p && p->next)
				gen_next(lug, shift(new_p(x, y, p->line[x]), lug),
						shift(new_p(x, y + 1, p->next->line[x]), lug));
			x++;
		}
		y++;
		p = p->next;
	}
	mlx_put_image_to_window(lug->mlx_ptr, lug->window, lug->image, 10, 10);
	return (1);
}
