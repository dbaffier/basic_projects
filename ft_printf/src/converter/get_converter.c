/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 23:32:03 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/11 05:45:59 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			convert_m(t_format *data)
{
	size_t		len;

	len = 1;
	if (!(data->flag.opts & OPT_MINUS))
		while (data->flag.width > len && data->flag.width--)
			write_char(data, data->flag.opts & OPT_ZERO ? '0' : ' ');
	write_char(data, '%');
	if (data->flag.opts & OPT_MINUS)
		while (data->flag.width > len && data->flag.width--)
			write_char(data, ' ');
}

int				get_converter(t_format *data)
{
	static t_convert	converter[] = {CONVERT_C, CONVERT_S, CONVERT_D,
		CONVERT_P, CONVERT_I, CONVERT_M, CONVERT_O, CONVERT_U, CONVERT_X,
		CONVERT_F, CONVERT_G, CONVERT_GX, CONVERT_GC, CONVERT_GS, CONVERT_GF,
		CONVERT_B, CONVERT_R, CONVERT_GR, CONVERT_K, CONVERT_GU, CONVERT_GO,
		CONVERT_GD};
	size_t				i;

	i = 0;
	while (i < sizeof(converter) / sizeof(converter[0]))
	{
		if (converter[i].type == *data->tail)
		{
			converter[i].func(data);
			return (1);
		}
		i++;
	}
	return (0);
}
