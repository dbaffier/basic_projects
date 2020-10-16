/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:13:48 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/21 16:01:49 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_basebis(uintmax_t n, char *base, size_t len)
{
	uintmax_t	nb;

	nb = n;
	if (nb >= len)
	{
		ft_putnbr_basebis(n / len, base, len);
		ft_putnbr_basebis(n % len, base, len);
	}
	else
		ft_putchar_fd(base[nb], 1);
}

void			ft_putnbr_base(uintmax_t n, char *base)
{
	ft_putnbr_basebis(n, base, ft_strlen(base));
}
