/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:42:19 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/18 10:26:55 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "ft_printf.h"
# include <limits.h>
# include "execute.h"

int		prompt(void);
int		h_prompt(void);
int		q_prompt(void);

#endif
