/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:20:11 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:57:18 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <ft_printf.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>

typedef void		(*t_funct)(char **, char ***);

typedef struct		s_call
{
	char	*s;
	t_funct	builtin;

}					t_call;

char				*get_occ(char *str);
int					check_exec(char **cmd, char **path);
int					cmd_exec(char **cmd, char **env);
char				**check_line(void);
size_t				count_w(char *s);
char				**ft_parse(char const *s, size_t size);

char				*get_var(char *key, char **env);
char				**get_path(char *path, char **envp);

int					builtin_handler(char **cmd, char ***envp);

int					is_exec(char *path, struct stat f, char **cmd, char **envp);
int					fork_exec(char **cmd, char **envp);

char				**setenv_builtinbis(char **cmd, char **env);

void				echo_builtin(char **cmd, char ***env);
void				setenv_builtin(char **cmd, char ***env);
void				env_builtin(char **cmd, char ***env);
void				exit_builtin(char **cmd, char ***env);
void				unsetenv_builtin(char **cmd, char ***env);
void				cd_builtin(char **cmd, char ***env);

void				signal_handler(int signo);
void				signal_infork(int signo);

void				dir_path(char ***env, char *path, char *cwd);
char				**clone(char **envp);
int					is_quote(int c);
void				ft_freetab(char ***tab);
int					get_n(char *str);

#endif
