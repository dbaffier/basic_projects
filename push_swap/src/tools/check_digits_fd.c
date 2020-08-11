/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 01:01:40 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/25 01:15:07 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			basic_space(char c)
{
	if (c == 32 || (c <= 8 && c >= 13))
		return (1);
	return (0);
}

static void			bound_check_up(t_stack *stack, char *line, int pos)
{
	int i;

	i = 0;
	while (line[pos] && !basic_space(line[pos]))
	{
		if (line[pos] > STR_MAX[i])
		{
			free(line);
			print_error(stack);
		}
		pos++;
		i++;
	}
}

static void			bound_checker_fd(t_stack *stack,
						char *line, int pos, char bound)
{
	int i;

	i = 0;
	if (bound == '-')
	{
		while (line[pos] && !basic_space(line[pos]))
		{
			if (line[pos] > STR_MIN[i])
			{
				free(line);
				print_error(stack);
			}
			pos++;
			i++;
		}
	}
	else
		bound_check_up(stack, line, pos);
}

static void			digits_checker_fd(t_stack *stack, char *line, int *i)
{
	int stop;

	if (line[*i] == 45 && (!line[*i + 1] || !ft_isdigit(line[*i + 1])))
		print_free_line(stack, line);
	stop = (line[*i] == 45) ? 0 : -1;
	*i = (line[*i] == 45) ? *i + 1 : *i;
	while (line[*i] && !basic_space(line[*i]))
	{
		if (line[*i] < 48 && line[*i] > 57)
			print_free_line(stack, line);
		stop++;
		if (stop == 11)
			print_free_line(stack, line);
		(*i)++;
	}
	if (stop == 10)
		bound_checker_fd(stack, line, (*i - 1) - stop, '-');
	if (stop == 9)
		bound_checker_fd(stack, line, (*i - 1) - stop, '+');
}

void				check_line(t_stack *stack, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] < 48 || line[i] > 57) && !basic_space(line[i]))
			print_free_line(stack, line);
		while ((line[i] >= 8 && line[i] <= 13) || line[i] == 32)
			i++;
		if (line[i] == 45 || (line[i] >= 48 && line[i] <= 57))
			digits_checker_fd(stack, line, &i);
	}
}
