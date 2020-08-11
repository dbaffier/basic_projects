/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:39:21 by mmonier           #+#    #+#             */
/*   Updated: 2019/08/13 01:56:28 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include <fcntl.h>

static void		print_letter(int fd)
{
	int ret;
	char buff;

	while ((ret = read(fd, &buff, 1)) > 0)
	{
		if (buff == ':')
			ft_printf("{CYAN}");
		else
			ft_printf("{BLUE}");
		ft_printf("%c{WHITE}", buff);
	}
}

static void	print_author(void)
{
	int fd;
	int ret;
	char buff;

	fd = open(".author", O_RDONLY);
	ft_printf("{GREEN}\t\t\t---------------------------------------------------------------------------\n{WHITE}");
	while ((ret = read(fd, &buff, 1) > 0))
		ft_printf("{PINK}%c{WHITE}", buff);
	ft_printf("{GREEN}\t\t\t---------------------------------------------------------------------------\n{WHITE}");
	close(fd);
}

static void read_and_close(char *str)
{
	int fd;

	system("clear");
	fd = open(str, O_RDONLY);
	print_letter(fd);
	close(fd);
}

static void	waiting(void)
{
	read_and_close(".lem-in");
	print_author();
	ft_printf("\n\n\n{PINK}Loading anthill .{WHITE}\n");
	sleep(1);
	system("clear");
	read_and_close(".lem-in");
	print_author();
	ft_printf("\n\n\n{PINK}Loading anthill . .{WHITE}\n");
	sleep(1);
	system("clear");
	read_and_close(".lem-in");
	print_author();
	ft_printf("\n\n\n{PINK}Loading anthill . . .{WHITE}\n");
	sleep(1);
}

void		print_lemin(void)
{
	read_and_close(".letter-L");
	usleep(500000);
	read_and_close(".letter-LE");
	usleep(500000);
	read_and_close(".letter-LEM");
	usleep(500000);
	read_and_close(".letter-LEMI");
	usleep(500000);
	read_and_close(".lem-in");
	usleep(500000);
	print_author();
	usleep(500000);
}

void		print_loading(void)
{
	print_lemin();
	ft_printf("\n\n\n{PINK}Loading anthill{WHITE}\n");
	usleep(550000);
	system("clear");
	waiting();
	sleep(2);
	read_and_close(".lem-in");
	print_author();
}

static void print_gap(int x)
{
	while (x > 0)
	{
		ft_printf(" ");
		x--;
	}
}

void		 print_square(int x, int y)
{
	int length;

	length  = 3;
	while (y > 0)
	{
		ft_printf("\n");
		y--;
	}
	print_gap(x);
	ft_printf("[%C]", L'🐜');
/*	while (length >= 0)
	{
		if (length == 3 || length == 0)
		{
			print_gap(x);
			printf("----\n");
		}
		else
		{
			print_gap(x - 1);
			printf("|    |\n");
		}
		length--;
	}*/
}
