/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:17:53 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/11 02:07:46 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_star(t_format *data, int work)
{
	int		star;
	int		star2;

	star = 0;
	star2 = 0;
	(void)work;
	if (msk(data, OPT_HSTAR))
	{
		get_arg_n(data, &star);
		if (data->flag.width == 0)
		{
			if (star < 0)
				data->flag.opts |= OPT_MINUS;
			data->flag.width = star < 0 ? star * -1 : star;
		}
	}
	if (data->flag.star)
	{
		get_arg_n(data, &star2);
		data->flag.precision = star2 < 0 ? data->flag.precision : star2;
		if (star2 < 0)
			data->flag.opts &= ~OPT_PREC;
	}
}
