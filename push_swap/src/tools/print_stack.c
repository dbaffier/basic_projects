/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:33:13 by dbaffier          #+#    #+#             */
/*   Updated: 2019/06/27 14:00:11 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <wchar.h>
#include <locale.h>

static int			total_instruction(t_stack *st)
{
	int		total;
	int		i;

	i = 0;
	total = 0;
	while (i < 11)
	{
		total += *((int *)st->print + i);
		i++;
	}
	return (total);
}

void				print_instruction_counter(t_stack *st, useconds_t speed)
{
	wchar_t *cross;

	cross = L"⤫";
	if (st->opts & OPT_N)
	{
		ft_printf("\n\n\t%S  Instruction counter  %S \n\n", L"🛠", L"🛠");
		ft_printf("PA  : {GREY}%d  {CYAN}\t%S\t{WHITE} ", st->print->pa, cross);
		ft_printf("PB  : {GREY}%d{WHITE}\n", st->print->pb);
		ft_printf("SA  : {GREY}%d  {CYAN}\t%S\t{WHITE} ", st->print->sa, cross);
		ft_printf("SB  : {GREY}%d ", st->print->sb);
		ft_printf("{CYAN}\t%S\t{WHITE} ", cross);
		ft_printf("SS  : {GREY}%d{WHITE}\n", st->print->ss);
		ft_printf("RA  : {GREY}%d  ", st->print->ra);
		ft_printf("{CYAN}\t%S\t{WHITE} RB  : {GREY}%d ", cross, st->print->rb);
		ft_printf("{CYAN}\t%S\t{WHITE} ", cross);
		ft_printf("RR  : {GREY}%d{WHITE}\n", st->print->rr);
		ft_printf("RRA : {GREY}%d ", st->print->rra);
		ft_printf("{CYAN}\t%S\t{WHITE} RRB : {GREY}%d ", cross, st->print->rrb);
		ft_printf("{CYAN}\t%S\t{WHITE} ", cross);
		ft_printf("RRR : {GREY}%d{WHITE}\n", st->print->rrr);
		ft_printf("\n    {GREY}   -----------------------------{WHITE}\n");
		ft_printf("TOTAL : \t{RED}%d{WHITE}\t", total_instruction(st));
	}
	usleep(speed);
}

void				speed_mode(t_stack *stack)
{
	wchar_t		*c;

	c = L"⚡️";
	if (stack->opts & OPT_Q && stack->opts & OPT_C)
	{
		ft_printf("\n\tSpeed mode : %S %S %S\n\n", L"⚡️", L"⚡️", L"⚡️");
		print_instruction_counter(stack, 100000);
	}
	else if (stack->opts & OPT_S && stack->opts & OPT_C)
	{
		ft_printf("\n\tSpeed mode : %S\n\n", L"⚡️");
		print_instruction_counter(stack, 400000);
	}
	else
	{
		if (stack->opts & OPT_C)
			ft_printf("\n\tSpeed mode : %S %S\n\n", L"⚡️", L"⚡️");
		print_instruction_counter(stack, 300000);
	}
}

static void			basic_print(t_stack *stack, char *instruc)
{
	t_pile		*a;
	t_pile		*b;
	int			cpt;

	a = stack->a;
	b = stack->b;
	cpt = 0;
	ft_printf("Executing : %s\n\n", instruc);
	while (cpt < stack->len_a || cpt < stack->len_b)
	{
		if (cpt < stack->len_a)
			ft_printf("%-10d ", a->n);
		else
			ft_printf("%-10s ", "");
		if (cpt < stack->len_b)
			ft_printf("%-10d \n", b->n);
		else
			ft_printf("%-10s \n", "");
		if (cpt < stack->len_a)
			a = a->next;
		if (cpt < stack->len_b)
			b = b->next;
		cpt++;
	}
	ft_printf("%-10c %-10c\n%-10c %-10c \n", '-', '-', 'a', 'b');
}

void				print_stack(t_stack *stack, char *instruc)
{
	count_instruction(stack, instruc);
	if (stack->opts & OPT_C)
	{
		executing_color(stack, instruc);
		return ;
	}
	system("clear");
	basic_print(stack, instruc);
	speed_mode(stack);
}
