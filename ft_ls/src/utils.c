/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:44:58 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/12 15:32:42 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_strstart(char *s, char *oc)
{
	int		i;

	i = 0;
	while (s[i] == oc[i])
		i++;
	if (!oc[i])
		return (1);
	return (0);
}

void			err_h(int err, char *msg)
{
	if (err == DIR_ACCESS_ERR)
		ft_putstr_fd(DIR_STRERR, 2);
	else if (err == NONEXISTENT_ERR)
	{
		write(2, "ls: ", 4);
		ft_putstr_fd(msg, 2);
		write(2, ": No such file or directory\n", 28);
	}
	else
	{
		write(2, "ls: ", 4);
		ft_putstr_fd(msg, 2);
		write(2, ": Permission denied\n", 20);
	}
}

int				has_nonprintable_chars(char *s, int len)
{
	int		i;

	i = -1;
	while (++i < len && s[i])
		if (is_nonprintable(s[i]))
			return (1);
	return (0);
}

void			error_handling(char *option)
{
	write(2, "ls: illegal option -- ", 22);
	write(2, &option[0], 1);
	write(2, "\n", 1);
	ft_putstr_fd(USAGE_ERR, 2);
	exit(1);
}
