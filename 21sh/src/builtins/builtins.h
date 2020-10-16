/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:49:05 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 15:40:36 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# define NODR_ERR "No such file or directory"
# define CD_ERR "cd: error retrieving current directory: getcwd: "NODR_ERR
# define SET_ERR1 "setenv: Variable name must contain alphanumeric characters."
# define SET_ERR2 "setenv: Variable name must begin with a letter."
# include <sys/stat.h>

typedef int		(*t_funct)(t_shell *sh);

typedef struct	s_call
{
	char	*s;
	t_funct	builtin;
}				t_call;

int				echo_builtin(t_shell *sh);
int				setenv_builtin(t_shell *sh);
int				env_builtin(t_shell *sh);
int				exit_builtin(t_shell *sh);
int				unsetenv_builtin(t_shell *sh);
int				cd_builtin(t_shell *sh);

int				builtins(t_shell *sh);

char			parse_echo(char *s);
int				echoo(char *s, char ***env);
int				cd_no_args(char ***env);
int				cd_one_arg(char *arg, char ***env, int p, char *tmp);
int				cd_go_back(char ***env);
int				cd_access(char *arg);
int				ft_strstrn(char *s1, char *s2);
char			*ft_replace_str(char *pwd, char *dst, char *src);
int				cd_two_args(char *arg1, char *arg2, char ***env, int p);
int				is_symlnk_option(char *s);
int				get_cd_options(t_shell *sh);
int				get_arg_index(t_shell *sh);
int				ft_find_last_char(char *s, char c);
int				is_option(t_shell *sh);
int				is_i_option(char *s);
int				count_options(t_shell *sh);
int				illegal_option(char *s);
int				get_to_set(t_shell *sh, int i);
int				is_to_set(char *s);
int				parse_env(t_shell *sh, int i, int count);
int				env_exec(char **cmd, char **envp, char **environ);
int				use_bin_exec(char **cmd, char **envp, char **environ);
int				try_paths(char *path, char **args, int success, char **environ);
void			error_msg(char *arg, int i);
int				set_env(char *var, char ***env);
int				is_value(char *var);
char			***add_var(char *var, char ***env);
char			***del_env_value(char *var, char ***env);
char			***add_var_value(char *var, char ***env);
char			***change_var_value(char *var, char ***env);
int				count_envp(char ***env);
int				find_char(char *s, char c);
char			***get_realloc(char ***env);
int				parse_var_name(char *name);
int				is_slashs(char *s);
void			print_pwd(char *oldpwd, char *newpwd);
int				is_option_n(char *s);
int				change_env_value(char *var, char *value, char ***env);
int				same_slashs(char *s1, char *s2);
char			*get_pwd(char *cwd, char *arg, char *tmp);
int				unset_env(t_shell *sh, int i, int j);
void			tmp_environ(t_shell *sh, int j);

#endif
