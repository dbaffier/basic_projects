/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:44:29 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/20 16:08:17 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			c_color(char *c, char *format)
{
	int		len;
	char	*color;

	len = ft_strlen(c);
	color = ft_strsub(format, 0, len);
	if (ft_strcmp(c, color))
	{
		free(color);
		return (0);
	}
	free(color);
	if (format[len] == '}')
		return (len + 1);
	else
		return (0);
}

int					ad_color(char **str)
{
	int		len;

	if ((len = c_color("black", *str)))
		ft_putstr(BLACK);
	else if ((len = c_color("red", *str)))
		ft_putstr(RED);
	else if ((len = c_color("green", *str)))
		ft_putstr(GREEN);
	else if ((len = c_color("yellow", *str)))
		ft_putstr(YELLOW);
	else if ((len = c_color("blue", *str)))
		ft_putstr(BLUE);
	else if ((len = c_color("magenta", *str)))
		ft_putstr(MAGENTA);
	else if ((len = c_color("cyan", *str)))
		ft_putstr(CYAN);
	else if ((len = c_color("white", *str)))
		ft_putstr(WHITE);
	else
		return (0);
	(*str) += len;
	return (1);
}
