/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:16:23 by aitoraudi         #+#    #+#             */
/*   Updated: 2024/01/15 00:39:12 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdbool.h>

# define WINX 1440
# define WINY 900

# define CHAR_READ 1000000

# define X 0
# define Y 1
# define Z 2

# define LAT 0
# define LONG 1

# define FIT 1
# define CHAR_NUMBER 500000
# define MARGIN 60
# define RED 0xc1272d
# define GREEN 0x33cc55
# define GREEN2 0X93dc9a
# define FUCSIA 0xff255c
# define BLUE 0x1B8EFA
# define SKYBLUE 0x0000FF
# define CARBON 0x151515
# define WHITE 0xBBBBBB
# define PURPLE 0x9A1F6A
# define BRICK_RED 0xC2294E
# define FLAMINGO 0xEC4B27
# define ORANGE 0xEF8633
# define SAFFRON 0xF3AF3D
# define BLUE2 0X3784f1

# define DEFAULT_COLOR BLUE
# define GROUND_COLOR GREEN2
# define TOP_COLOR BRICK_RED
# define BOTTOM_COLOR BLUE2
# define NUMBER_COLOR WHITE
# define TEXT_COLOR WHITE
# define BACKGROUND_COLOR CARBON
# define MENU_COLOR 0x202020

# define MENU_WIDTH 330
# define FIT_MARGIN 100

# define FIT 1
# define FREE 0

typedef struct s_point
{
	float		axis[3];
	int			color;
	int			hex_color;
	bool		paint;
	float		polar[2];
}				t_point;

typedef struct m_colors
{
	int			top;
	int			ground;
	int			bottom;
	int			background;
	int			menu;
}				t_colors;

typedef struct s_img
{
	void		*image;
	char		*addr;
	int			bitxpixel;
	int			lines;
	int			endian;
}				t_img;

typedef struct s_win
{
	void		*mlx;
	void		*win;
}				t_win;

typedef struct s_keys
{
	bool		b_mouse_l;
	bool		b_mouse_r;
	bool		b_keyctrl;
	t_point		last_click_l;
	t_point		last_click_r;
}				t_keys;

typedef struct m_map
{
	char		*memory;
	char		**lines;
	int			zmin;
	float		ang[3];
	float		zdivisor;
	float		scale;
	int			len;
	float		brange;
	int			renders;
	t_point		*points;
	t_point		limits;
	t_point		source;
	t_colors	colors;
	bool		b_lines;
	bool		b_dots;
	bool		b_pluslines;
	bool		sphere;
	bool		b_stars;
	bool		b_shadow;
	double		performance;
	float		proportion;
	float		radius;
	bool		m_terrain;
}				t_map;

typedef struct s_fdf
{
	t_img		img;
	t_map		map;
	t_win 	win;
	t_keys		keys;
}				t_fdf;

# define DEF_COLOR "\033[0;39m"
# define SH_GRAY "\033[0;90m"
# define SH_RED "\033[0;91m"
# define SH_GREEN "\033[0;92m"
# define SH_YELLOW "\033[0;93m"
# define SH_BLUE "\033[0;94m"
# define SH_MAGENTA "\033[0;95m"
# define SH_CYAN "\033[0;96m"
# define SH_WHITE "\033[0;97m"
# define SH_KNR "\x1B[0m"
# define SH_KRED "\x1B[31m"
# define SH_KGRN "\x1B[32m"
# define SH_KYEL "\x1B[33m"
# define SH_KBLU "\x1B[34m"
# define SH_KMAG "\x1B[35m"
# define SH_KCYN "\x1B[36m"
# define SH_KWHT "\x1B[37m"
# define U_ORANGE "\033[48:5:208m"
# define U_WHITE "\033[37;7:208m"
# define U_YELLOW "\033[33;7:208m"
# define U_BLUE "\033[34;7:208m"

#endif
