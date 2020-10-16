/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:14:27 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 13:57:19 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_ulen(t_flags *flags, uintmax_t n)
{
	if (F->LEN == 1)
		n = (short unsigned int)n;
	else if (F->LEN == 2)
		n = (unsigned char)n;
	else if (F->LEN == 3)
		n = (long unsigned int)n;
	else if (F->LEN == 4)
		n = (unsigned long long int)n;
	else if (F->LEN == 5)
		n = (uintmax_t)n;
	else if (F->LEN == 6)
		n = (size_t)n;
	else
		n = (unsigned int)n;
	return (n);
}

intmax_t		get_len(t_flags *flags, intmax_t n)
{
	if (F->LEN == 1)
		n = (short int)n;
	else if (F->LEN == 2)
		n = (char)n;
	else if (F->LEN == 3)
		n = (long int)n;
	else if (F->LEN == 4)
		n = (long long int)n;
	else if (F->LEN == 5)
		n = (intmax_t)n;
	else if (F->LEN == 6)
		n = (size_t)n;
	else
		n = (int)n;
	return (n);
}
