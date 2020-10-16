/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:42:21 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 12:01:39 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "astree.h"

# define REDIR_ERROR		0
# define REDIR_OK			1

int					ft_redirect(t_redirection *rd);
int					ft_herecdoc(t_redirection *rd);
int					agregation_file(t_redirection *rd);
int					exec_rd_pipe(t_redirection *rd);
int					init_rd_pipe(t_astree *tree);
int					init_redir(t_redirection *rd);
int					exec_redir_pipe(t_redirection *rd);
int					ft_open_err(int fd, char *file);
int					get_fd(t_redirection *redir);
int					make_dup2(char *dst, int target, int from);

void				restore_std_fd(t_redirection *rd, int save[3]);
void				close_pipe_rd(t_redirection *redir);

#endif
