/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:22:24 by mmonier           #+#    #+#             */
/*   Updated: 2020/01/03 14:23:16 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_abs(int x)
{
	return (x > 0 ? x : -x);
}

static void		prepare_bre(t_draw *dr)
{
	dr->dx = dr->x2 - dr->x1;
	dr->dy = dr->y2 - dr->y1;
	dr->xin = dr->dx >= 0 ? 1 : -1;
	dr->yin = dr->dy >= 0 ? 1 : -1;
	dr->dx = ft_abs(dr->x2 - dr->x1);
	dr->dy = ft_abs(dr->y2 - dr->y1);
	dr->e = (dr->dx > dr->dy) ? dr->dx / 2 : dr->dy / 2;
}

static void		draw_right(t_lug *lug, t_draw *draw, int color)
{
	if (draw->x1 + (WIDTH * draw->y1) < WIDTH * HEIGHT * 4)
		((int *)lug->str)[draw->x1 + (WIDTH * draw->y1)] = color;
	draw->e = draw->e - draw->dy;
	if (draw->e < 0)
	{
		draw->y1 += draw->yin;
		draw->e = draw->e + draw->dx;
	}
	draw->x1 += draw->xin;
}

static void		draw_bottom(t_lug *lug, t_draw *draw, int color)
{
	if (draw->x1 + (WIDTH * draw->y1) < WIDTH * HEIGHT * 4)
		((int *)lug->str)[draw->x1 + (WIDTH * (draw->y1 + 1))] = color;
	draw->e = draw->e - draw->dx;
	if (draw->e < 0)
	{
		draw->x1 += draw->xin;
		draw->e = draw->e + draw->dy;
	}
	draw->y1 += draw->yin;
}

int				bresenham(t_lug *lug, t_draw *draw, int color)
{
	prepare_bre(draw);
	if (draw->dx > draw->dy)
	{
		while (draw->x1 < draw->x2 && draw->xin > 0)
			draw_right(lug, draw, color);
		while (draw->x1 > draw->x2 && draw->xin < 0)
			draw_right(lug, draw, color);
	}
	else
	{
		while (draw->y1 < draw->y2 && draw->yin > 0)
			draw_bottom(lug, draw, color);
		while (draw->y1 > draw->y2 && draw->yin < 0)
			draw_bottom(lug, draw, color);
	}
	return (1);
}
