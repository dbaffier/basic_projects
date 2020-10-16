/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:42:12 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/12 15:26:14 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdarg.h>

# define F		flags

# define CW		check_width
# define CP		check_precision
# define W		width
# define P		precision
# define PR		prefix
# define F0		zero
# define SP		space
# define SG		sign
# define LA		left_align
# define LEN	length
# define SPC	specifier

struct			s_n
{
	uintmax_t		n;
	unsigned int	n_strlen;
	unsigned int	n_len;
	int				full;
};

typedef struct	s_flags
{
	int		left_align;
	int		sign;
	int		space;
	int		zero;
	int		prefix;
	char	specifier;

	int		check_precision;
	int		precision;

	int		check_width;
	int		width;

	int		length;
}				t_flags;

int				ft_printf(const char *format, ...);

typedef int		(*t_converter)(t_flags *, va_list *);
t_converter		get_converter(char *c);

void			get_flags(char **str, t_flags *flags);
void			get_width(char **str, t_flags *flags);
void			get_precision(char **str, t_flags *flags);
void			get_length(char **str, t_flags *flags);
void			get_specifier(char **str, t_flags *flags);
int				check_specifier(char *c);

void			print_char(t_flags *flags, char c);
void			print_wchar(t_flags *flags, wchar_t c);
int				print_string(t_flags *flags, char *str);
int				print_wstring(t_flags *flags, wchar_t *str);
void			print_binary_uint(uintmax_t n);
int				print_int(intmax_t n, t_flags *flags, int c);

int				convert_wchar(t_flags *flags, va_list *c);
int				convert_char(t_flags *flags, va_list *c);
int				convert_string(t_flags *flags, va_list *str);
int				convert_wstring(t_flags *flags, va_list *wstr);
int				convert_modulo(t_flags *flags, va_list *c);
int				convert_binary(t_flags *flags, va_list *c);
int				convert_unsign(t_flags *flags, va_list *c);
int				convert_hexa(t_flags *flags, va_list *c);
int				convert_octal(t_flags *flags, va_list *c);
int				convert_address(t_flags *flags, va_list *c);
int				convert_int(t_flags *flags, va_list *c);
int				convert_long(t_flags *flags, va_list *c);

void			shuffle(t_flags *flags);
void			print_padding(int start, int end, char c);
int				ft_putunsign(t_flags *flags, uintmax_t n,
								char *base, char *prefix);
t_flags			*init_struct(void);
unsigned int	ft_nstrlen(t_flags *flags, uintmax_t n, char *base);
int				print_prefix_max(intmax_t n, t_flags *flags,
									char *prefix, char *base);
int				print_prefix(uintmax_t n, t_flags *flags,
								char *prefix, char *base);
int				handle_prefix(t_flags *flags, intmax_t n, char *prefix);
int				n_len_max(intmax_t n, char *base);
int				n_strlen_max(t_flags *flags, intmax_t n, char *base);
uintmax_t		get_ulen(t_flags *flags, uintmax_t n);
intmax_t		get_len(t_flags *flags, intmax_t n);
int				ad_color(char **str);
int				check_fl(char **str);
void			get_max_length(char **str, t_flags *flags);
void			get_flags_p(char **str, t_flags *flags);

#endif
