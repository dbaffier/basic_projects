/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:43:32 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 10:00:47 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <unistd.h>

int		fill_pipe(int flag, int pipread, int *subfds, t_piped *piped)
{
	if (piped == NULL)
		return (-1);
	if (pipe(subfds) == -1)
	{
		write(2, "Pipe error\n", 11);
		return (-1);
	}
	piped->fds = subfds;
	piped->flag = flag;
	piped->pipread = pipread;
	return (1);
}
