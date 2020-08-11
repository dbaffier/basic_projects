/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 04:28:41 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/25 04:06:49 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				count_instruction(t_stack *stack, char *str)
{
	if (ft_strcmp(str, "pa") == 0)
		stack->print->pa = stack->print->pa + 1;
	else if (ft_strcmp(str, "pb") == 0)
		stack->print->pb = stack->print->pb + 1;
	else if (ft_strcmp(str, "sa") == 0)
		stack->print->sa = stack->print->sa + 1;
	else if (ft_strcmp(str, "sb") == 0)
		stack->print->sb = stack->print->sb + 1;
	else if (ft_strcmp(str, "ss") == 0)
		stack->print->ss = stack->print->ss + 1;
	else if (ft_strcmp(str, "ra") == 0)
		stack->print->ra = stack->print->ra + 1;
	else if (ft_strcmp(str, "rb") == 0)
		stack->print->rb = stack->print->rb + 1;
	else if (ft_strcmp(str, "rr") == 0)
		stack->print->rr = stack->print->rr + 1;
	else if (ft_strcmp(str, "rra") == 0)
		stack->print->rra = stack->print->rra + 1;
	else if (ft_strcmp(str, "rrb") == 0)
		stack->print->rrb = stack->print->rrb + 1;
	else if (ft_strcmp(str, "rrr") == 0)
		stack->print->rrr = stack->print->rrr + 1;
}

void				exec_instruction(t_stack *stack, char *str)
{
	static t_apply	tab[] = {PA, PB, RA, RB, RR, RRA, RRB, RRR, SA, SB, SS};
	size_t			i;
	int				itt;

	i = 0;
	itt = 4;
	while (ft_strcmp(str, tab[i].instruction) != 0)
		i++;
	tab[i].func(stack, stack->a, stack->b);
	if (stack->opts & OPT_C)
	{
		ft_printf("{GREEN}%s{WHITE}", tab[i].instruction);
		usleep(303330);
		while (itt--)
			ft_printf("\b");
	}
	ft_printf("%s\n", tab[i].instruction);
}

void				exec_multiple(t_stack *stack, char *s1, char *s2)
{
	exec_instruction(stack, s1);
	exec_instruction(stack, s2);
}
