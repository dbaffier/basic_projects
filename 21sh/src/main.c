/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:11:43 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 11:29:28 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int		main(int ac, char **av, char **envp)
{
	t_shglobal	*sh_save;

	(void)ac;
	(void)av;
	sh_save = init_tsh(envp);
	main_loop(sh_save);
	return (0);
}
