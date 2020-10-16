/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 03:46:23 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/14 03:47:44 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "converter.h"

int		is_unreal(t_format *data, double n)
{
	if (n == 1.0 / 0.0)
		write_str(data, "inf");
	else if (n == 1.0 / -0.0)
		write_str(data, "inf");
	else if (n != n)
		write_str(data, "nan");
	else
		return (0);
	return (1);
}

void	infinite(t_format *data, t_convf *ptr, double n)
{
	if (n == 1.0 / 0.0)
	{
		data->flag.opts &= ~OPT_ZERO;
		ptr->n_len = 3;
	}
	if (n == 1.0 / -0.0)
	{
		data->flag.opts &= ~OPT_ZERO;
		ptr->n_len = 4;
	}
	if (n != n)
	{
		data->flag.opts &= ~OPT_ZERO;
		ptr->n_len = 3;
	}
}
