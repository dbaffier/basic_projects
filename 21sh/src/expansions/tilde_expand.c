/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:02:57 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 12:02:18 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "expansions.h"
#include "utils.h"
#include <pwd.h>
#include <uuid/uuid.h>

static void		get_tilde_flags(t_tilde *tilde)
{
	struct passwd		*user;

	if (tilde->prefix == NULL)
		tilde->flags |= TILDE_NO;
	else if (ft_strcmp(tilde->prefix, "+") == 0)
		tilde->flags |= TILDE_PLUS;
	else if (ft_strcmp(tilde->prefix, "-") == 0)
		tilde->flags |= TILDE_LESS;
	else if ((user = getpwnam(tilde->prefix)) != NULL)
	{
		tilde->user = user;
		tilde->flags |= TILDE_USER;
	}
}

static char		*get_tpwd(t_tilde *tilde, char ***env)
{
	if (tilde->flags & TILDE_PLUS)
		return (get_var("PWD", *env));
	else if (tilde->flags & TILDE_LESS)
		return (get_var("OLDPWD", *env));
	else if (tilde->flags & TILDE_USER)
		return (tilde->user->pw_dir);
	else if (tilde->flags & TILDE_NO)
		return (get_var("HOME", *env));
	return (NULL);
}

static char		*get_expand(char *str, char ***env, t_tilde *tilde)
{
	char		*new;
	char		*pwd;

	if (!ft_strcmp(str, "~"))
	{
		free(str);
		return (ft_strdup(get_var("HOME", *env)));
	}
	get_prefix(str + 1, tilde);
	if (tilde->flags & TILDE_QUOTED)
		return (NULL);
	get_tilde_flags(tilde);
	if (((pwd = get_tpwd(tilde, env))) == NULL)
		return (str);
	new = ft_strdup(pwd);
	new = ft_strjoinfree(new, str + (ft_strlen(tilde->prefix) + 1), 1);
	free(str);
	return (new);
}

char			*expand_tilde(char *str, char ***env)
{
	t_tilde		tilde;
	char		*new;

	ft_bzero(&tilde, sizeof(t_tilde));
	new = get_expand(str, env, &tilde);
	free(tilde.prefix);
	return (new);
}
