/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:03:41 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/25 03:43:44 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		highlight_num_b(t_pile *b, char *instruc, int cpt)
{
	if (cpt == 0 && identify_instruc(instruc, 1))
		ft_printf("  {BLUE}% -10d{WHITE} \n", b->n);
	else if (cpt == 0 && identify_instruc(instruc, 2))
		ft_printf("   {CYAN}% -15d{WHITE} \n", b->n);
	else
		ft_printf("   % -10d \n", b->n);
}

static void		highlight_num_a(t_pile *a, char *instruc, int cpt)
{
	if (cpt == 0 && identify_instruc(instruc, 0))
		ft_printf("   {GREEN}% -15d{WHITE} ", a->n);
	else if (cpt == 0 && identify_instruc(instruc, 2))
		ft_printf("   {CYAN}% -15d{WHITE} ", a->n);
	else
		ft_printf("   % -15d ", a->n);
}

static void		print_stack_color(t_stack *stack, char *instruc)
{
	t_pile		*a;
	t_pile		*b;
	int			cpt;

	a = stack->a;
	b = stack->b;
	cpt = 0;
	while (cpt < stack->len_a || cpt < stack->len_b)
	{
		if (cpt < stack->len_a)
			highlight_num_a(a, instruc, cpt);
		else
			ft_printf("   %-15s ", "");
		show_action(stack, instruc);
		if (cpt < stack->len_b)
			highlight_num_b(b, instruc, cpt);
		else
			ft_printf("   %-10s \n", "");
		if (cpt < stack->len_a)
			a = a->next;
		if (cpt < stack->len_b)
			b = b->next;
		cpt++;
	}
}

static void		print_top_color(void)
{
	ft_printf("\t{GREEN}%C ", L'⧽');
	ft_printf("{GREEN}%s {WHITE}", "a");
	ft_printf("\t\t    {BLUE}%C ", L'⧽');
	ft_printf("{BLUE}%s {WHITE}\n", "b");
	ft_printf("     -----------------------------\n");
}

void			executing_color(t_stack *stack, char *instruc)
{
	int len;

	len = 4;
	system("clear");
	ft_printf("\t   {CYAN}Executing  : %s {GREEN}%C{WHITE}\n\n", instruc, L'✓');
	print_top_color();
	print_stack_color(stack, instruc);
	speed_mode(stack);
	system("clear");
	ft_printf("\t   {CYAN}Executing  : %s {RED}%C{WHITE}\n\n", instruc, L'✓');
	print_top_color();
	print_stack_color(stack, instruc);
	speed_mode(stack);
	system("clear");
	ft_printf("\t   {CYAN}Executing  : %s {GREEN}%C{WHITE}\n\n", instruc, L'✓');
	print_top_color();
	print_stack_color(stack, instruc);
	speed_mode(stack);
}
