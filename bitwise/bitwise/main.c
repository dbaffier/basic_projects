/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:00:59 by dbaffier          #+#    #+#             */
/*   Updated: 2018/05/12 18:53:26 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putwchar(wchar_t c)
{
	if (c <= 127)
		ft_putchar(c);
	else if (c <= 2047)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 65535)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 1114111)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

void	print_bits(char octet)
{
	int		z;
	int		oct;
	
	z = 128;
	oct = octet;
	while (z != 0)
	{
		if (z <= oct)
		{
			write(1, "1", 1);
			oct = oct % z;
		}
		else
			write(1, "0", 1);
		z = z / 2;
	}
}

void	ft_putwstr(wchar_t *s)
{
	while (*s)
		ft_putwchar(*s++);
}

int main(int ac, char **av)
{
	unsigned char b;
	unsigned char c;

	//setlocale( LC_ALL, "en_US.UTF-8" );

	b = 5; //00000101
	c = 2;
	print_bits(b);
	ft_putchar('\n');
	print_bits(c);
	ft_putchar('\n');
	print_bits(b & c);
	ft_putchar('\n');
	ft_putwchar(132);
	wprintf(L"%lc", "\u2713");
	ft_putwchar(135);
	(void)ac;
	(void)av;
	return (0);
}
