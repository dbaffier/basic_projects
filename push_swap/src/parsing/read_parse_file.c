/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_parse_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:23:14 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/25 01:06:35 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			check_fd(t_stack *stack, const int fd)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		check_line(stack, line);
		stock_in(stack, line);
		free(line);
	}
}

int					read_file(t_stack *stack, char **av, int ac)
{
	int i;
	int fd;

	i = stack->start_reading ? stack->start_reading : 1;
	fd = 0;
	while (i < ac)
	{
		if (i > stack->start_reading)
		{
			close(fd);
			print_error(stack);
		}
		if ((fd = open(av[i], O_RDONLY)) < 0)
			usage_flag_f(stack, av[i]);
		check_fd(stack, fd);
		i++;
	}
	if (!duplicate_entry(stack->a, stack))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
