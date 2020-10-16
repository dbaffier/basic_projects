/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:54:29 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:27:52 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"
#include "expansions.h"

void		expand_cmd(t_cmd *lst, t_shglobal *shg)
{
	if (!lst)
		return ;
	while (lst)
	{
		if (lst->cmd && lst->cmd[0] == '~' && !(lst->cmd[1] == '$'))
			lst->cmd = expand_tilde(lst->cmd, &shg->env);
		if (ft_strchr(lst->cmd, '$') || ft_strchr(lst->cmd, '\\'))
			lst->cmd = expand_dollar(lst->cmd, shg);
		lst = lst->next;
	}
}
