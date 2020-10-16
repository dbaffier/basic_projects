/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exaust_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:20:36 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 10:02:36 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "astree.h"

void		exaust_cmd(t_tok **lst, t_cmd **cmd)
{
	t_cmd	*ptr;

	if (!lst || !*lst)
		return ;
	if (*cmd == NULL)
	{
		*cmd = create_cmd((*lst)->data, (*lst)->type);
		*lst = (*lst)->next;
	}
	else
	{
		ptr = *cmd;
		while (ptr && ptr->next != NULL)
			ptr = ptr->next;
		while (*lst)
		{
			if ((*lst)->operator == OPERATOR || (*lst)->operator == IO_NUMBER)
				return ;
			ptr->next = create_cmd((*lst)->data, (*lst)->type);
			ptr = ptr->next;
			*lst = (*lst)->next;
		}
	}
}
