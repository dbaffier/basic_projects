/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:57:22 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 13:57:38 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_nstrlen(t_flags *flags, uintmax_t n, char *base)
{
	unsigned int	n_len;
	unsigned int	nstr_len;

	n_len = ft_nbase_len(n, base);
	if (n == 0 && F->CP && F->P == 0)
		nstr_len = 1;
	else if (F->CP)
		nstr_len = ft_max(n_len, F->P);
	else
		nstr_len = n_len;
	return (nstr_len);
}
