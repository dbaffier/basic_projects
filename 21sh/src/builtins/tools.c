/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:59:08 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 15:51:13 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "ft_printf.h"
#include "builtins.h"
#include "utils.h"

int		ft_strstrn(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (s2[0] == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			j++;
			if (!s2[j])
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_replace_str(char *pwd, char *dst, char *src)
{
	int		i;
	int		j;
	int		s;
	char	*tmp;

	tmp = ft_strnew(ft_strlen(pwd) - ft_strlen(dst) + ft_strlen(src) + 1);
	j = -1;
	i = ft_strstrn(pwd, dst);
	if (i == -1)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		p_err(dst, NULL, NULL, 2);
		return (tmp);
	}
	while (++j < i)
		tmp[j] = pwd[j];
	s = 0;
	while (src[s])
		tmp[j++] = src[s++];
	i += ft_strlen(dst);
	while (pwd[i])
		tmp[j++] = pwd[i++];
	tmp[j] = '\0';
	return (tmp);
}

int		parse_var_name(char *name)
{
	int	i;

	i = 0;
	while (name[i] == '_')
		i++;
	if (name[i] && !ft_isalnum(name[i]))
	{
		p_err(SET_ERR1, NULL, NULL, 2);
		return (1);
	}
	else if (!i && !ft_isalpha(name[0]))
	{
		p_err(SET_ERR2, NULL, NULL, 2);
		return (1);
	}
	return (0);
}

void	print_pwd(char *homepwd, char *newpwd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (homepwd[i] && newpwd[i] && homepwd[i] == newpwd[i])
		i++;
	newpwd = ft_strsub(newpwd, i, ft_strlen(newpwd) - i);
	tmp = ft_strjoin("~", newpwd);
	ft_printf("%s\n", tmp);
	free(newpwd);
	free(tmp);
}

int		change_env_value(char *var, char *value, char ***env)
{
	int		i;
	char	*tmp;

	i = -1;
	if (value)
	{
		while ((*env)[++i])
		{
			tmp = ft_strsub((*env)[i], 0, ft_find_char((*env)[i], '='));
			if (ft_strcmp(tmp, var) == 0)
			{
				ft_strdel(&tmp);
				free((*env)[i]);
				(*env)[i] = NULL;
				tmp = ft_strjoin(var, "=");
				(*env)[i] = ft_strjoin(tmp, value);
				ft_strdel(&tmp);
				return (1);
			}
			ft_strdel(&tmp);
		}
		add_var(var, env);
		change_env_value(var, value, env);
	}
	return (0);
}
