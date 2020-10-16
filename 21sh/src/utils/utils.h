/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:48:39 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/21 19:10:11 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/stat.h>

struct passwd *pw;

char	**clone(char **envp);
char	**first_clone(char **envp, int i);
char	*get_var(char *key, char **env);
char	**get_env(char *path, char **envp);

void	err(char *msg, char *err, int out, int exit);
void	perm_file(char *path, struct stat f, int perm);
void	p_err(char *prefix, char *msg, char *suffix, int fd);
void	ft_freetab(char ***tab);

int		ft_find_char(char *s, char c);
int		ft_isnum(char *str);
int		ft_strdigits(char *str);

char	**init_env_i(void);
int		get_alloc_size(char **envp);
char	**init_env(char **clone, char **envp, int i);

#endif
