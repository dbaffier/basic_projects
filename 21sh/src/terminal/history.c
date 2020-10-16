/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:10:58 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 16:43:48 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
** save new command on history.txt file, add new node in doubly list
*/

int		save_history(char *line, char *home)
{
	int		fd;
	char	*path;

	path = ft_strjoin(home, "/21_history.txt");
	fd = open(path, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		free(path);
		ft_putstr("can't open file\n");
		return (1);
	}
	if (write(fd, line, (int)ft_strlen(line)) != (int)ft_strlen(line) ||
			(write(fd, "\n", 1) != 1))
	{
		free(path);
		ft_putendl("Error writing to history.txt\n");
		close(fd);
		return (1);
	}
	new_node(line);
	close(fd);
	free(path);
	return (0);
}

/*
** add new node in doubly list
*/

void	new_node(char *new_line)
{
	struct s_hlist *new_node;

	if (!(new_node = (struct s_hlist*)malloc(sizeof(struct s_hlist))))
		return ;
	new_node->line = ft_strdup(new_line);
	new_node->next = head;
	new_node->prev = NULL;
	if (head != NULL)
		head->prev = new_node;
	head = new_node;
}

/*
** create doubly list with already existing commands in history.txt,
** if there is any
*/

void	create_hlist(char *home, int i)
{
	int				fd;
	char			*line;
	char			buff[2];
	char			*path;

	path = ft_strjoin(home, "/21_history.txt");
	if (!(fd = open(path, O_RDWR | O_CREAT, 0644)))
		return (ft_putstr_fd("Can't open file \n", 2));
	line = ft_strnew(1);
	while ((i = read(fd, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
		{
			new_node(line);
			line[0] = '\0';
		}
		else
		{
			buff[i] = '\0';
			line = ft_strjoinfree(line, buff, 1);
		}
	}
	free(line);
	free(path);
	close(fd);
}

/*
** browse up in history of commands
*/

char	*browse_up(struct s_hlist ***temp)
{
	if (!(**temp))
		return (NULL);
	if ((**temp)->next)
	{
		(**temp) = (**temp)->next;
		return ((**temp)->prev->line);
	}
	return ((**temp)->line);
}

/*
** browse down in history of commands
*/

char	*browse_down(struct s_hlist ***temp)
{
	if (!(**temp))
		return (NULL);
	if ((**temp)->prev)
	{
		(**temp) = (**temp)->prev;
		return ((**temp)->line);
	}
	return ("\0");
}
