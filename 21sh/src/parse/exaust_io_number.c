/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exaust_io_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:49:06 by dbaffier          #+#    #+#             */
/*   Updated: 2019/01/26 17:26:50 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "astree.h"

static void		exaust_w_ionumber(t_tok **lst,
		t_redirection **redir)
{
	t_redirection	*ptr;

	ptr = *redir;
	while (ptr && ptr->next != NULL)
		ptr = ptr->next;
	while (*lst)
	{
		if (!((*lst)->operator == IO_NUMBER))
			return ;
		ptr->next = create_redir((*lst)->data, (*lst)->next->next->data,
				NULL, (*lst)->next->type);
		ptr = ptr->next;
		free((*lst)->next->data);
		*lst = (*lst)->next->next->next;
	}
}

void			exaust_ionumber(t_tok **lst, t_redirection **redir)
{
	if (!redir)
		return ;
	if (*redir == NULL)
	{
		*redir = create_redir((*lst)->data, (*lst)->next->next->data,
				NULL, (*lst)->next->type);
		free((*lst)->next->data);
		*lst = (*lst)->next->next->next;
	}
	else
		exaust_w_ionumber(lst, redir);
}
