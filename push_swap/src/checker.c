/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:26:05 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 11:55:38 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort(t_stack *st)
{
	if (lst_sorted(st))
	{
		if (st->opts & OPT_C)
			ft_printf("  {GREEN}%S{WHITE} ", L"✓");
		ft_printf("OK\n");
	}
	else
	{
		if (st->opts & OPT_C)
			ft_printf("  {RED}%S{WHITE} ", L"✕");
		ft_printf("KO\n");
	}
}

int				main(int ac, char **av)
{
	t_stack		st;
	t_print		print;
	size_t		i;

	if (ac < 2)
		print_usage("./checker");
	i = 1;
	ft_memset(&st, 0, sizeof(st));
	st.print = &print;
	ft_bzero(&print, sizeof(print));
	if (check_global_flags(&st, av, ac) == 0)
		return (help("CK"));
	if (st.opts & OPT_F)
	{
		st.opts &= ~OPT_PS;
		read_file(&st, av, ac);
	}
	else
		check_input(&st, av, ac);
	st.len_a = st.a->prev->id;
	handle_instructions(&st);
	sort(&st);
	free_pile(st.a, st.len_a);
	free_pile(st.b, st.len_b);
	return (0);
}
