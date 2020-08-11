/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 08:20:02 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 20:57:32 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		exit_if(t_stack *stack, char c)
{
	if (!((c >= 48 && c <= 57) || c == 32 || c == 45))
		print_error(stack);
}

static void		bound_checker(t_stack *stack, char *str, int pos, char bound)
{
	int i;

	i = 0;
	if (bound == '-')
	{
		while (str[pos] && str[pos] != 32)
		{
			if (str[pos] > STR_MIN[i])
				print_error(stack);
			pos++;
			i++;
		}
	}
	else
	{
		while (str[pos] && str[pos] != 32)
		{
			if (str[pos] > STR_MAX[i])
				print_error(stack);
			pos++;
			i++;
		}
	}
}

static void		digits_checker(t_stack *stack, char *str, int *i)
{
	int stop;

	if (str[*i] == 45 && (!str[*i + 1] || !ft_isdigit(str[*i + 1])))
		print_error(stack);
	stop = (str[*i] == 45) ? 0 : -1;
	*i = (str[*i] == 45) ? *i + 1 : *i;
	while (str[*i] && str[*i] != 32)
	{
		if (!(str[*i] >= 48 && str[*i] <= 57))
			print_error(stack);
		stop++;
		if (stop == 11)
			print_error(stack);
		(*i)++;
	}
	if (stop == 10)
		bound_checker(stack, str, (*i - 1) - stop, '-');
	if (stop == 9)
		bound_checker(stack, str, (*i - 1) - stop, '+');
}

static void		import_input(t_stack *stack, char *str)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		exit_if(stack, str[i]);
		if (str[i] == 45 || (str[i] >= 48 && str[i] <= 57))
		{
			count = 1;
			digits_checker(stack, str, &i);
		}
		while (str[i] == 32)
			i++;
	}
	if (count == 0)
		print_error(stack);
}

int				check_input(t_stack *stack, char **av, int ac)
{
	int i;

	if (av[1] && av[1][0] == '\0')
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!av[stack->start_reading])
		return (0);
	i = stack->start_reading ? stack->start_reading : 1;
	while (i < ac)
	{
		import_input(stack, av[i]);
		stock_in(stack, av[i]);
		i++;
	}
	if (!duplicate_entry(stack->a, stack))
		return (0);
	return (1);
}
