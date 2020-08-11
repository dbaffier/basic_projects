/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:00:07 by dbaffier          #+#    #+#             */
/*   Updated: 2020/01/03 14:28:40 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "ft_printf.h"
# include "mlx.h"
# include <math.h>

# define WIDTH		1024
# define HEIGHT		1024

# define MLX_WHITE	0x7FFFFFFF
# define MLX_RED	0xFF0000
# define MLX_GREEN	0x00FF00
# define MLX_BLUE	0x0000FF
# define MLX_YELLOW	0xFFFF00

typedef struct		s_p
{
	int				*line;
	int				size;
	struct s_p		*next;
}					t_p;

typedef struct		s_lug
{
	int				list_size;
	char			*progname;
	t_p				*cord;
	void			*mlx_ptr;
	void			*window;
	void			*image;
	char			*str;
	int				zoom;
	int				x_off;
	int				y_off;
	double				alpha;
	double				beta;
	double				gamma;
	struct s_draw	*draw;
}					t_lug;

typedef struct		s_pt
{
	int		x;
	int		y;
	int		z;
}					t_pt;

typedef	struct		s_draw
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				xin;
	int				yin;
	int				e;
}					t_draw;

enum
{
	ERR_OPEN = 1,
	ERR_ARG,
	ERR_MALLOC,
};

int					keyhook(int key, t_lug *lug);
int					parse(t_lug *lug, char *map);
char				**ft_strsplitws(const char *s);
int					drawline(t_lug *lug);
int					ft_init(t_lug *lug, char *name);
int					fdf(t_lug *lug);
int					bresenham(t_lug *lug, t_draw *draw, int color);
int					draw(t_lug *lug, int *tab, int size, int x, int y);

void				rotate_x(int *y, int *z, double alpha);
void				rotate_y(int *x, int *z, double beta);
void				rotate_z(int *x, int *y, double gamma);


#endif
