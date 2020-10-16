/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:34:13 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/23 08:38:30 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(char **str, t_flags *flags)
{
	while (**str && ((**str == '#') || (ft_isdigit(**str)
			|| (**str == '-') || (**str == '+')
			|| (**str == ' '))))
	{
		if (**str == '#')
			F->PR = 1;
		if (**str == '0')
			F->F0 = 1;
		if (**str == ' ')
			F->SP = 1;
		if (**str == '+')
			F->SG = 1;
		if (**str == '-')
			F->LA = 1;
		if (**str >= '1' && **str <= '9')
			get_width(str, flags);
		else
			(*str)++;
	}
}

void	get_width(char **str, t_flags *flags)
{
	if (F->W)
		return ;
	while (**str && ft_isdigit(**str))
	{
		F->CW = 1;
		F->W = (F->W * 10) + (**str - '0');
		(*str)++;
	}
}

void	get_precision(char **str, t_flags *flags)
{
	if (**str == '.')
	{
		F->CP = 1;
		(*str)++;
		while (**str == '.')
			(*str)++;
		if (!(ft_isdigit(**str)))
		{
			F->CP = 2;
			F->P = 1;
		}
		while (**str && ft_isdigit(**str))
		{
			F->P = F->P * 10 + (**str - '0');
			(*str)++;
		}
	}
}

void	get_length(char **str, t_flags *flags)
{
	if (**str == 'h' || **str == 'l'
			|| **str == 'j' || **str == 'z')
	{
		if (**str == 'h')
		{
			F->LEN = *(*str + 1) == 'h' ? 2 : 1;
			if (F->LEN == 2)
				(*str)++;
		}
		else if (**str == 'l')
		{
			F->LEN = *(*str + 1) == 'l' ? 4 : 3;
			if (F->LEN == 4)
				(*str)++;
		}
		else if (**str == 'j')
			F->LEN = 5;
		else if (**str == 'z')
			F->LEN = 6;
		(*str)++;
	}
}

void	get_specifier(char **str, t_flags *flags)
{
	if (**str)
	{
		if (**str == '#')
		{
			F->PR = 1;
			(*str)++;
		}
		if (check_specifier(&(**str)))
		{
			F->SPC = **str;
			(*str)++;
		}
	}
}
