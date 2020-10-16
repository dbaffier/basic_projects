/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:04:12 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/21 16:01:31 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putunsignbis(t_flags *flags, struct s_n data, char *prefix)
{
	if (F->CW && !F->LA && !F->F0)
		print_padding(data.n_strlen, (F->PR ? F->W - data.full : F->W), ' ');
	if ((F->PR || F->SPC == 'p') && prefix && data.n)
		ft_putstr_fd(prefix, 1);
	if (F->CW && F->F0 && data.n != 0 && (F->CP == 0 || F->CP > 2))
		print_padding(data.n_len, (F->W - data.full), '0');
	else if (F->CP)
	{
		if (F->PR &&
				(F->SPC != 'X' && F->SPC != 'x'))
			print_padding(data.n_len + data.full, data.n_strlen, '0');
		else
		{
			if (F->SPC == 'p')
				print_padding(data.n_len + 2, data.n_strlen, '0');
			else
				print_padding(data.n_len, data.n_strlen, '0');
		}
	}
	if (F->CP == 2 && F->CW && !F->LA
			&& (F->SPC != 'x' && F->SPC != 'X'))
		print_padding(data.n_len, F->W, ' ');
}

int				ft_putunsign(t_flags *flags, uintmax_t n,
							char *base, char *prefix)
{
	struct s_n	data;

	data.full = 0;
	data.n = n;
	if (prefix != NULL && n != 0 && F->PR)
		data.full = ft_strlen(prefix);
	data.n_len = ft_nbase_len(data.n, base);
	data.n_strlen = ft_nstrlen(flags, data.n, base);
	data.n_strlen = (F->SPC == 'p') ? data.n_strlen += 2 : data.n_strlen;
	ft_putunsignbis(flags, data, prefix);
	ft_putnbr_base(data.n, base);
	if (F->CW && F->LA)
		print_padding(data.n_strlen, F->W - data.full, ' ');
	if (F->CW)
		return (ft_max(F->W, data.n_strlen + data.full));
	else
	{
		if (F->CP && F->PR
			&& F->P > (int)data.n_len
			&& (F->SPC != 'x' && F->SPC != 'X'))
			return (data.n_strlen);
		return (data.n_strlen + data.full);
	}
}
