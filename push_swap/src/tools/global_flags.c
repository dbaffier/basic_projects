/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:03:21 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 12:09:05 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	neg_num(char *av)
{
	if (av && av[0] == '-' && ft_isdigit(av[1]))
		return (1);
	return (0);
}

void		usage_flag_f(t_stack *stack, char *str)
{
	if (stack->opts & OPT_PS)
		ft_printf("%s -f [%s] : no such file\n", PS, str);
	else
		ft_printf("%s -f [%s] : no such file\n", CK, str);
	if (stack->a)
		free_pile(stack->a, stack->len_a);
	if (stack->b)
		free_pile(stack->b, stack->len_b);
	exit(42);
}

int			check_global_flags(t_stack *stack, char **av, int ac)
{
	int i;

	i = 1;
	if (ft_strcmp(av[1], "--help") == 0 || ft_strcmp(av[1], "-h") == 0)
		return (0);
	while (i < ac)
	{
		if (av[i] && (av[i][0] != '-'
					|| neg_num(av[i]) || ft_isdigit(av[i][0])))
			break ;
		flag_get(stack, av[i]);
		i++;
	}
	if ((stack->start_reading = i) == ac)
		stack->opts & OPT_PS ? print_usage(PS) : print_usage(CK);
	if (stack->opts & OPT_C && !(stack->opts & OPT_V))
	{
		if (stack->a)
			free_pile(stack->a, stack->len_a);
		if (stack->b)
			free_pile(stack->b, stack->len_b);
		ft_printf("usage : -v required to use -c\n");
		exit(42);
	}
	return (1);
}
