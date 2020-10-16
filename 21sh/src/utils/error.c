/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:29:50 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/18 10:15:22 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"

void	p_err(char *prefix, char *msg, char *suffix, int fd)
{
	write(fd, prefix, ft_strlen(prefix));
	write(fd, msg, ft_strlen(msg));
	write(fd, suffix, ft_strlen(suffix));
	write(fd, "\n", 1);
}

void	err(char *msg, char *err, int out, int v)
{
	if (v)
	{
		ft_printf("%s %s\n", msg, err);
		exit(out);
	}
	else
		ft_printf("%s %s\n", msg, err);
}
