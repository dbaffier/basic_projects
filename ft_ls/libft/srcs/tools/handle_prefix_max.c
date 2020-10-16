/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prefix_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:57:47 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 13:57:12 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			n_len_max(intmax_t n, char *base)
{
	int		i;
	size_t	b_len;

	b_len = ft_strlen(base);
	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= b_len;
		i++;
	}
	return (i);
}

int			n_strlen_max(t_flags *flags, intmax_t n, char *base)
{
	int		n_len;
	int		n_strlen;

	n_len = n_len_max(n, base);
	if (n == 0 && F->CP && F->P == 0)
		n_strlen = 0;
	else if (F->CP)
		n_strlen = ft_max(n_len, F->P);
	else
		n_strlen = n_len;
	return (n_strlen);
}

int			print_prefix_max(intmax_t n, t_flags *flags,
		char *prefix, char *base)
{
	int		n_len;
	int		c_p;
	int		c_l;

	c_p = (!ft_strcmp(prefix, " ") ? 0 : 1);
	n_len = n_strlen_max(flags, n, base);
	c_l = ft_strlen(prefix);
	if (F->CP && !F->LA && !F->F0)
	{
		c_l = 0;
		print_padding(n_len, F->W - c_p, ' ');
	}
	else if (F->CW)
		F->W -= ft_strlen(prefix);
	if (n >= -9223372036854775807)
		ft_putstr_fd(prefix, 1);
	return (c_l + n_len);
}

int			print_prefix(uintmax_t n, t_flags *flags, char *prefix, char *base)
{
	unsigned int	n_strlen;
	unsigned int	n_len;
	unsigned int	p_c;
	int				p_l;

	p_c = (!ft_strcmp(prefix, " ") ? 0 : 1);
	n_strlen = ft_nstrlen(flags, n, base);
	n_len = ft_nbase_len(n, base);
	p_l = ft_strlen(prefix);
	if (F->W && !F->LA && !F->F0)
	{
		print_padding(n_strlen, F->W - p_c, ' ');
		F->W -= ft_strlen(prefix);
	}
	else if (F->CW)
		F->W -= ft_strlen(prefix);
	ft_putstr_fd(prefix, 1);
	return (p_l + n_strlen);
}
