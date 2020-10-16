/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expand2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:44:43 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 15:56:19 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"
#include "ft_printf.h"
#include "utils.h"

void			get_last_arg(t_cmd *cmd, t_shglobal *shg)
{
	if (cmd)
	{
		while (cmd->next != NULL)
			cmd = cmd->next;
	}
	if (shg->arg_status)
		free(shg->arg_status);
	if (cmd && cmd->cmd)
		shg->arg_status = ft_strdup(cmd->cmd);
	else
		shg->arg_status = ft_strdup("0");
}

char			*search_expand(char *expand, t_shglobal *shg)
{
	char		*new;

	new = NULL;
	if (expand == NULL)
		return (NULL);
	if (expand && expand + 1)
		new = get_var(expand + 1, shg->env);
	else
		return (NULL);
	if (new)
		return (new);
	else
		return (NULL);
}

char			*add_expand(char *s1, char *s2, int flags)
{
	if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (s1);
	else
	{
		if (flags == 1)
			return (ft_strjoinfree(s1, s2, 1));
		else if (flags == 2)
			return (ft_strjoinfree(s1, s2, 2));
		else
			return (ft_strjoinfree(s1, s2, 3));
	}
}

char			*add_string(char *s1, char *s2, int flags)
{
	if (s1 == NULL)
		return (s2);
	else if (s2 == NULL)
		return (s1);
	else
	{
		if (flags == 1)
			return (ft_strjoinfree(s1, s2, 1));
		else if (flags == 2)
			return (ft_strjoinfree(s1, s2, 2));
		else
			return (ft_strjoinfree(s1, s2, 3));
	}
}

char			*expand_special(char c, t_shglobal *shg)
{
	if (c == '?')
		return (ft_itoa(shg->exit_status));
	else if (c == '_')
	{
		if (shg->arg_status == NULL)
			return (getcwd(NULL, 0));
		else
			return (ft_strdup(shg->arg_status));
	}
	else if (c == '$')
		return (ft_itoa(getpid()));
	else if (c == '0')
		return (ft_strdup("21sh"));
	else
		return (NULL);
}
