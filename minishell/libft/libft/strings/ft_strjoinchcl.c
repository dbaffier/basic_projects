/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchcl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:33:06 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/13 13:47:28 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchcl(char *s1, char c)
{
	char	*new;

	if (!(new = ft_strjoinch(s1, c)))
		return (NULL);
	free(s1);
	s1 = NULL;
	return (new);
}
