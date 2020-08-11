/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 23:48:36 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/14 06:44:52 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_atoin(char *str, int *i, int sign)
{
	int		result;
	int		len;

	result = 0;
	len = 0;
	*i = (sign == -1) ? *i + 1 : *i;
	while (str[*i] && str[*i] != 32)
	{
		result = result * 10 + (str[*i] - 48);
		len++;
		(*i)++;
	}
	return (result * sign);
}

void			stock_in(t_stack *stack, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 45)
			lst_insert(&stack->a, ft_atoin(str, &i, -1));
		if (str[i] >= 48 && str[i] <= 57)
			lst_insert(&stack->a, ft_atoin(str, &i, 1));
		if (str[i])
			i++;
	}
}
