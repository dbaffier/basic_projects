/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:58:22 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/07 12:42:54 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_specifier(char *c)
{
	char	*converter;

	converter = "sSpdDioOuUxXcCb%";
	if (ft_strchr(converter, *c))
		return (1);
	return (0);
}

void			get_max_length(char **str, t_flags *flags)
{
	if (**str == 'h' || **str == 'l'
			|| **str == 'j' || **str == 'z')
	{
		if (**str == 'h' && *(*str + 1) == 'h'
				&& F->LEN == 0)
		{
			(*str)++;
			F->LEN = 2;
		}
		if (**str == 'h' && F->LEN == 2)
			F->LEN = 1;
		if (**str == 'l' && *(*str + 1) == 'l' && F->LEN != 5)
		{
			(*str)++;
			F->LEN = 4;
		}
		if (**str == 'l' && (!(F->LEN == 5 || F->LEN == 4)))
			F->LEN = 3;
		if (**str == 'z' && (F->LEN == 2 || F->LEN == 1))
			F->LEN = 6;
		if (**str == 'j')
			F->LEN = 5;
		(*str)++;
	}
}

void			get_flags_p(char **str, t_flags *flags)
{
	if (**str >= '1' && **str <= '9')
		get_width(str, flags);
	get_flags(str, flags);
	get_width(str, flags);
	get_precision(str, flags);
	if (**str == '.')
	{
		F->P = 0;
		get_precision(str, flags);
	}
	get_length(str, flags);
	if (F->LEN)
	{
		while (**str)
		{
			get_max_length(str, flags);
			get_flags(str, flags);
			if (!check_fl(str))
				break ;
		}
	}
}

int				check_fl(char **str)
{
	if (**str == 'h' || **str == 'l')
	{
		if (**str == 'h')
		{
			if (*(*str + 1) == 'h')
			{
				(*str)++;
				return (1);
			}
			return (1);
		}
		else if (**str == 'l')
		{
			if (*(*str + 1) == 'l')
			{
				(*str)++;
				return (1);
			}
			return (1);
		}
	}
	if (**str == 'j' || **str == 'z')
		return (1);
	return (0);
}

t_converter		get_converter(char *c)
{
	if (*c == 'c')
		return (&convert_char);
	else if (*c == 'C')
		return (&convert_wchar);
	else if (*c == 's')
		return (&convert_string);
	else if (*c == 'S')
		return (&convert_wstring);
	else if (*c == '%')
		return (&convert_modulo);
	else if (*c == 'b')
		return (&convert_binary);
	else if (*c == 'u')
		return (&convert_unsign);
	else if (*c == 'x' || *c == 'X')
		return (&convert_hexa);
	else if (*c == 'o')
		return (&convert_octal);
	else if (*c == 'p')
		return (&convert_address);
	else if (*c == 'd' || *c == 'i')
		return (&convert_int);
	else if (*c == 'O' || *c == 'U' || *c == 'D')
		return (&convert_long);
	return (NULL);
}
