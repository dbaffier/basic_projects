/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:59:34 by dbaffier          #+#    #+#             */
/*   Updated: 2020/01/03 14:22:06 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move(int key, t_lug *lug)
{
	if (key == 4)
		lug->x_off -= 10;
	else if (key == 38)
		lug->y_off += 10;
	else if (key == 40)
		lug->y_off -= 10;
	else if (key == 37)
		lug->x_off += 10;
}

static void	rotation(int key, t_lug *lug)
{
	if (key == 12)
		lug->alpha += 0.05;
	else if (key == 13)
		lug->alpha -= 0.05;
	else if (key == 14)
		lug->beta += 0.05;
	else if (key == 15)
		lug->beta -= 0.05;
	else if (key == 16)
		lug->gamma += 0.05;
	else if (key == 17)
		lug->gamma -= 0.05;
}

static void	zoom(int key, t_lug *lug)
{
	if (key == 24)
		lug->zoom++;
	else if (key == 27)
		lug->zoom--;
	if (lug->zoom < 1)
		lug->zoom = 1;
}

int			keyhook(int key, t_lug *lug)
{
	if (key == 53)
		exit(1);
	move(key, lug);
	rotation(key, lug);
	zoom(key, lug);
	ft_memset(lug->str, 0, (WIDTH * HEIGHT) * 4);
	printf("%d\n", key);
	fdf(lug);
	return (0);
}
