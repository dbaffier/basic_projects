/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:36:53 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 14:25:21 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_max_fd(intmax_t n, int fd)
{
	uintmax_t	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	if (nbr >= 10)
	{
		ft_putnbr_max_fd(nbr / 10, fd);
		ft_putnbr_max_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}
