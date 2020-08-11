/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 03:42:45 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/25 03:46:52 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			identify_instruc(char *instruc, int mod)
{
	if (mod == 0)
	{
		if (ft_strcmp(instruc, "pa") == 0 || ft_strcmp(instruc, "ra") == 0
				|| ft_strcmp(instruc, "rra") == 0
				|| ft_strcmp(instruc, "sa") == 0)
			return (1);
	}
	else if (mod == 1)
	{
		if (ft_strcmp(instruc, "pb") == 0 || ft_strcmp(instruc, "rb") == 0
					|| ft_strcmp(instruc, "rrb") == 0
					|| ft_strcmp(instruc, "sb") == 0)
			return (1);
	}
	else if (mod == 2)
		if (ft_strcmp(instruc, "rr") == 0
				|| ft_strcmp(instruc, "rrr") == 0
				|| ft_strcmp(instruc, "ss") == 0)
			return (1);
	return (0);
}

void		get_action(char *instruc)
{
	if (ft_strcmp(instruc, "pb") == 0)
		ft_printf("{BLUE}%-5C {WHITE}", L'➝');
	else if (ft_strcmp(instruc, "pa") == 0)
		ft_printf("{GREEN}%-5C{WHITE}", L'←');
	else if (ft_strcmp(instruc, "ra") == 0)
		ft_printf("{GREEN}%-5C{WHITE}", L'↑');
	else if (ft_strcmp(instruc, "rb") == 0)
		ft_printf("{BLUE}%-5C{WHITE}", L'↑');
	else if (ft_strcmp(instruc, "rr") == 0)
		ft_printf("{CYAN}%-5C{WHITE}", L'⇈');
	else if (ft_strcmp(instruc, "rra") == 0)
		ft_printf("{GREEN}%-5C{WHITE}", L'↓');
	else if (ft_strcmp(instruc, "rrb") == 0)
		ft_printf("{BLUE}%-5C {WHITE}", L'↓');
	else if (ft_strcmp(instruc, "rrr") == 0)
		ft_printf("{CYAN}%-5C{WHITE}", L'⇊');
	else if (ft_strcmp(instruc, "sa") == 0)
		ft_printf("{GREEN}%-5C{WHITE}", L'⤾');
	else if (ft_strcmp(instruc, "sb") == 0)
		ft_printf("{BLUE}%-5C {WHITE}", L'⤿');
	else if (ft_strcmp(instruc, "ss") == 0)
		ft_printf("{CYAN}%-5C{WHITE}", L'⥀');
}

void		show_action(t_stack *stack, char *instruc)
{
	static	int done = 0;
	int			reset;

	reset = stack->len_a > stack->len_b ? stack->len_a : stack->len_b;
	if (done == 0)
		get_action(instruc);
	else
	{
		ft_printf("{GREY}%-5C{WHITE}", L'⏐');
		if (done == reset - 1)
			done = -1;
	}
	done++;
}
