/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:02:27 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 12:03:13 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

void			free_lst_tok(t_tok *tok);
void			free_shell(t_shell *sh);
void			destroy_syntax_tree(t_lstastree *lst);

#endif
