/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:24:49 by dbaffier          #+#    #+#             */
/*   Updated: 2018/07/09 18:37:44 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list		*head;

	head = *alst;
	if (!(*alst))
		*alst = new;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
}
