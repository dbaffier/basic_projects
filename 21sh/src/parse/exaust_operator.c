/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exaust_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:43:34 by dbaffier          #+#    #+#             */
/*   Updated: 2019/01/26 17:27:27 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "astree.h"

static void		exaust_w_operator(t_tok **lst, t_redirection **redir)
{
	t_redirection	*ptr;

	ptr = *redir;
	while (ptr && ptr->next != NULL)
		ptr = ptr->next;
	while (*lst)
	{
		if (!((*lst)->operator == OPERATOR))
			return ;
		else if ((*lst)->type & SEMICOLON || (*lst)->type & PIPE)
			return ;
		if ((*lst)->type & DLESSER)
			ptr->next = create_redir(NULL, (*lst)->next->data,
				(*lst)->herecdoc, (*lst)->type);
		else
			ptr->next = create_redir(NULL, (*lst)->next->data,
					NULL, (*lst)->type);
		free((*lst)->data);
		ptr = ptr->next;
		*lst = (*lst)->next->next;
	}
}

void			exaust_operator(t_tok **lst, t_redirection **redir)
{
	if (!redir)
		return ;
	if (*redir == NULL)
	{
		free((*lst)->data);
		if ((*lst)->type & DLESSER)
			*redir = create_redir(NULL, (*lst)->next->data,
					(*lst)->herecdoc, (*lst)->type);
		else
			*redir = create_redir(NULL, (*lst)->next->data,
					NULL, (*lst)->type);
		*lst = (*lst)->next->next;
	}
	else
		exaust_w_operator(lst, redir);
}
