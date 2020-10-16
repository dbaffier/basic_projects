/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:33:42 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 03:51:03 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		sign;
	int		result;

	result = n;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	sign = (n < 0 ? -1 : 1);
	if (n < 0)
		n = -n;
	if (sign == -1)
		ft_putchar('-');
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
