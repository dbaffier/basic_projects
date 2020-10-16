/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:49:01 by dbaffier          #+#    #+#             */
/*   Updated: 2019/01/25 11:34:33 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_freetab(char ***tab)
{
	char	**ptr;
	int		i;

	if (*tab)
	{
		ptr = *tab;
		i = 0;
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(*tab);
		*tab = NULL;
	}
}
