/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:56:11 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/24 16:51:41 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define BUFF_SIZE 16
# define LIMIT '\n'

# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define BOLD_RED		"\033[1;31m"
# define ITALIC_RED		"\033[3;31m"
# define GREEN			"\033[1;32m"
# define BOLD_GREEN		"\033[1;32m"
# define ITALIC_GREEN	"\033[3;32m"
# define YELLOW			"\033[33m"
# define BOLD_YELLOW	"\033[1;33m"
# define ITALIC_YELLOW	"\033[3;33m"
# define BLUE			"\033[34m"
# define BOLD_BLUE		"\033[1;34m"
# define ITALIC_BLUE	"\033[3;34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[1;37m"

# define CHAR_BIT 8
# define INT_MAX 2147483647

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strjoinchfree(char *s1, char c);
char				*ft_strtoupper(char *str);
char				*ft_strjoinchcl(char *s1, char c);
char				*ft_strreplace(char *str, char *term, char *replace_by);
int					ft_stralpha(char *str);
char				*ft_strjoinfree(char const *s1, char const *s2, int a);
int					is_alphanum(char *str);
int					ft_startstr(char *s1, char *s2);
void				ft_putsl(char const *s, char c);
char				**ft_splitws(char const *s);
int					is_nonprintable(char c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isdigits(char *s);

int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));

char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_strdel(char **as);
void				ft_strclr(char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstcount(t_list *alst);
void				ft_lstpushback(t_list **alst, t_list *new);

int					ft_copyuntil(char **dst, char *src, char c);
int					ft_countwords(char const *str, char c);
int					ft_islower(char c);
int					ft_isupper(char c);
char				*ft_strjoinch(char const *s1, char c);

void				ft_putwchar(wchar_t c);
void				ft_strrev(char *str, int len);
int					ft_pow(int x, unsigned int y);
void				ft_ftoa(float n, char *res, int afterpoint);

void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);
void				ft_putwstr(wchar_t *str);
char				*ft_phexa(unsigned int num, char *str, int c);
void				ft_putaddress(unsigned int ad, char *buff);
size_t				ft_strnlen(char *str, size_t len);
void				ft_putnstr(char *str, int len);
int					ft_max(int a, int b);
size_t				ft_wstrnlen(wchar_t *str, size_t len);
size_t				ft_wstrnlenbis(wchar_t *s, size_t len, size_t i);
void				ft_putnwstr(wchar_t *str, size_t len);
size_t				ft_wstrlen(wchar_t *s);
void				ft_putnbr_base(uintmax_t n, char *base);
unsigned int		ft_nbase_len(uintmax_t n, char *base);
void				ft_putnbr_max(intmax_t n);
void				ft_putnbr_max_fd(intmax_t n, int fd);
int					read_line(int fd, t_list *current);
int					get_next_line(int const fd, char **line);
int					ft_strendswith(const char *s1, char *s2);
char				*ft_pathjoin(const char *p1, const char *p2);
char				*ft_strndup(const char *s1, size_t n);
int					ft_intlen(int num);

#endif
