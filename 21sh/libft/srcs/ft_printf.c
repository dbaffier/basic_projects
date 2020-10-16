/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:06:44 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/07 12:42:26 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		specifier_error(t_flags *flags, char **str)
{
	int		ret;

	ret = 0;
	if (F->W && !F->LA && !F->CP)
		print_padding(1, F->W, ' ');
	else if (F->CP && !F->LA)
		print_padding(1, F->W, '0');
	if (F->SPC)
		ft_putchar_fd('%', 1);
	else if (F->SPC == 0)
	{
		if (**str)
		{
			ret = ((**str == '%') ? 0 : 1);
			ft_putchar_fd(**str, 1);
			(*str)++;
		}
	}
	if (F->CW && F->LA)
		print_padding(1, F->W, ' ');
	if (F->W)
		ret += F->W - 1;
	return (ret);
}

static void		p_c(char **str, t_flags *flags)
{
	while ((**str == '0' || **str == '#'
				|| **str == '-' || **str == '+') && **str)
	{
		if (**str == '+')
			F->SG = 1;
		(*str)++;
	}
}

static int		parse_fmt(char **str, va_list *ap)
{
	t_flags			*flags;
	int				ret;
	t_converter		converter;

	ret = 0;
	if (!(flags = init_struct()))
		return (-1);
	get_flags_p(str, flags);
	p_c(str, flags);
	if (!**str)
		return (0);
	get_specifier(str, flags);
	shuffle(flags);
	if ((converter = get_converter(&(flags->SPC))))
	{
		if ((ret = (*converter)(flags, ap)) == -1)
			return (-1);
	}
	else
		ret = specifier_error(flags, str);
	free(flags);
	return (ret);
}

static int		ft_printfbis(const char *fmt, va_list *ap)
{
	char	*str;
	int		count;
	int		length;
	char	c;

	count = 0;
	str = (char *)fmt;
	while (*str)
	{
		c = *str++;
		if (c == '%')
		{
			if ((length = parse_fmt(&str, ap)) == -1)
				return (-1);
			count += length;
		}
		else if (c == '{' && ad_color(&str))
			;
		else
		{
			ft_putchar_fd(c, 1);
			count++;
		}
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	int			done;

	done = 0;
	va_start(arg, format);
	if (*format == '\0')
		return (0);
	done = ft_printfbis(format, &arg);
	va_end(arg);
	return (done);
}
