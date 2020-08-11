/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 05:35:28 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 12:54:35 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ps_helper(void)
{
	ft_printf("\nNAME\n");
	ft_printf("\t./push_swap [options] [-f file] [arg..]\n\n");
	ft_printf("OPTIONS\n");
	ft_printf("\t-h --help\tShow this message\n");
	ft_printf("\t-v\t\tNeeded in case of using -c\n");
	ft_printf("\t-c\t\tDisplay push_swap actions with colors\n");
	ft_printf("\t-r\t\tAsks push_swap to sort the input reversly\n");
	ft_printf("\t-f\t\tInput from a file\n\n");
	ft_printf("INSTRUCTIONS\n");
	ft_printf("\tsa sb (ss)\tSwap two top list elements in a/b ");
	ft_printf("(does it in the two lists at the same time)\n");
	ft_printf("\tpa pb\t\tPush the top element of a/b to the top of b/a\n");
	ft_printf("\tra rb (rr)\tFirst element becomes last ");
	ft_printf("(does it in the two lists at the same time)\n");
	ft_printf("\trra rrb (rrr)\tLast element becomes first ");
	ft_printf("(does it in the two lists at the same time)\n\n");
	return (0);
}

static int		ck_helper(void)
{
	ft_printf("\nNAME\n");
	ft_printf("\t./checker [options] [-f file] [arg..]\n\n");
	ft_printf("OPTIONS\n");
	ft_printf("\t-h --help\tShow this message\n");
	ft_printf("\t-v\t\tDisplay checker lists and actions\n");
	ft_printf("\t-c\t\tDisplay checker lists and actions with colors\n");
	ft_printf("\t-r\t\tAsks checker to check the sorting reversly\n");
	ft_printf("\t-n\t\tShow counter of instructions\n");
	ft_printf("\t-qs\t\tSpeed options quick - slow\n");
	ft_printf("\t-f\t\tInput from a file\n\n");
	ft_printf("INSTRUCTIONS\n");
	ft_printf("\tsa sb (ss)\tSwap two top list elements in a/b ");
	ft_printf("(does it in the two lists at the same time)\n");
	ft_printf("\tpa pb\t\tPush the top element of a/b to the top of b/a\n");
	ft_printf("\tra rb (rr)\tFirst element becomes last ");
	ft_printf("(does it in the two lists at the same time)\n");
	ft_printf("\trra rrb (rrr)\tLast element becomes first ");
	ft_printf("(does it in the two lists at the same time)\n\n");
	return (0);
}

int				help(char *str)
{
	if (ft_strcmp(str, "PS") == 0)
		return (ps_helper());
	if (ft_strcmp(str, "CK") == 0)
		return (ck_helper());
	return (0);
}
