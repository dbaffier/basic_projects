/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:24:49 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/09 11:25:36 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list		*tmp;
	t_list		*head;

	tmp = *alst;
	head = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	*alst = head;
}
