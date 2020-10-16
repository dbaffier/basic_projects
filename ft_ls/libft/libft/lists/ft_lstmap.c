/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:37:04 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/07 14:28:58 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;
	t_list		*next;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	next = new;
	while (lst)
	{
		tmp = f(lst);
		if (!(next->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		next = next->next;
	}
	return (new);
}
