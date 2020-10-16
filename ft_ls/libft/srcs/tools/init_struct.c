/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:48:38 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 12:20:39 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*init_struct(void)
{
	t_flags		*flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	F->LA = 0;
	F->SG = 0;
	F->SP = 0;
	F->F0 = 0;
	F->PR = 0;
	F->CP = 0;
	F->P = 0;
	F->CW = 0;
	F->W = 0;
	F->LEN = 0;
	F->SPC = 0;
	return (flags);
}
