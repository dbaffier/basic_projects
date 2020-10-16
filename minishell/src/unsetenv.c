/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:23:28 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/09 16:43:06 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unsetenv_builtin(char **cmd, char ***env)
{
	char	**ep;
	char	**sp;
	size_t	len;

	if (cmd[0] == NULL || cmd[0][0] == '\0' || ft_strchr(cmd[0], '=') != NULL)
		return ;
	len = ft_strlen(cmd[0]);
	ep = *env;
	while (*ep != NULL)
	{
		if (ft_strncmp(*ep, cmd[0], len) == 0 && (*ep)[len] == '=')
		{
			free(*ep);
			sp = ep;
			while (*sp != NULL)
			{
				*sp = *(sp + 1);
				sp++;
			}
		}
		else
			ep++;
	}
}
