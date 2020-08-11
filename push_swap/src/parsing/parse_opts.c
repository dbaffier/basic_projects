/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:56:28 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/24 22:49:51 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		set_msk(t_stack *stack, int msk)
{
	stack->opts |= msk;
}

static int		parse_flag(t_stack *stack, char c)
{
	static t_flags	tab[] = {FLG_V, FLG_C, FLG_R, FLG_F, FLG_S, FLG_Q, FLG_N};
	size_t			i;

	i = 0;
	while (i < sizeof(tab) / sizeof(*tab))
	{
		if (tab[i].flag == c)
		{
			set_msk(stack, tab[i].msk);
			return (0);
		}
		i++;
	}
	return (1);
}

void			flag_get(t_stack *stack, char *s)
{
	size_t		i;

	i = 1;
	if (s[0] && s[0] == '-' && s[1] && !ft_isdigit(s[1]))
	{
		while (s[i])
		{
			if (parse_flag(stack, s[i]))
				print_flag_err(stack, s[i]);
			i++;
		}
	}
}
