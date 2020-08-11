/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 05:06:02 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 11:28:26 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					check_instructions(t_stack *stack, char *line)
{
	static t_apply	tab[] = {PA, PB, RA, RB, RR, RRA, RRB, RRR, SA, SB, SS};
	size_t			i;

	i = 0;
	while (i < sizeof(tab) / sizeof(*tab))
	{
		if (ft_strcmp(line, tab[i].instruction) == 0)
		{
			tab[i].func(stack, stack->a, stack->b);
			if (stack->opts & OPT_PS)
				ft_printf("%s\n", tab[i].instruction);
			if (stack->opts & OPT_V)
				print_stack(stack, tab[i].instruction);
			return (1);
		}
		i++;
	}
	return (0);
}

void				handle_instructions(t_stack *stack)
{
	int			ret;
	char		*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line && line[0] == '\0')
		{
			free(line);
			return ;
		}
		if (!ft_strcmp(line, ""))
		{
			free(line);
			return ;
		}
		if (check_instructions(stack, line) == 0)
		{
			free(line);
			print_error(stack);
		}
		free(line);
	}
}
