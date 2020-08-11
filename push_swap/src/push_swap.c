/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 05:23:33 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 12:05:02 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack *st)
{
	if (st->a)
		st->len_a = st->a->prev->id;
	if (st->a && !lst_sorted_give(st, st->a, st->len_a))
	{
		if (st->a->prev->id == 3 || st->a->prev->id == 2
				|| st->a->prev->id == 4)
			lst_sort_three(st, st->a);
		else if (st->a->prev->id == 5)
			lst_sort_five(st);
		else
			lst_sort(st);
	}
	if (st->opts & OPT_R)
		lst_sort_reverse(st);
}

int			main(int ac, char **av)
{
	t_stack		st;
	t_print		print;
	size_t		i;

	i = 1;
	if (ac < 2)
		print_usage("./push_swap");
	ft_memset(&st, 0, sizeof(st));
	st.print = &print;
	st.opts |= OPT_PS;
	if (check_global_flags(&st, av, ac) == 0)
		return (help("PS"));
	if (st.opts & OPT_F)
		read_file(&st, av, ac);
	else
		check_input(&st, av, ac);
	sort(&st);
	free_pile(st.a, st.len_a);
	free_pile(st.b, st.len_b);
	return (0);
}
