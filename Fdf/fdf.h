/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:04:14 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/18 16:57:33 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define MLX_ERROR 1
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define ISO_ANGLE 0.523599
# define COLOR 0x00FF00
# define BLACK 0X000000

# define ZOOM_FACTOR 1.1
# define TRANS_FACTOR_X 10
# define TRANS_FACTOR_Y 10
# define ALTITUDE 0.1

# ifndef ESC_KEY
#  define ESC_KEY 65307
# endif
# ifndef RIGHT_KEY
#  define RIGHT_KEY 65363
# endif
# ifndef LEFT_KEY
#  define LEFT_KEY 65361
# endif
# ifndef UP_KEY
#  define UP_KEY 65362
# endif
# ifndef DOWN_KEY
#  define DOWN_KEY 65364
# endif
# ifndef F1_KEY
#  define F1_KEY 65470
# endif
# ifndef F2_KEY
#  define F2_KEY 65471
# endif
# ifndef F3_KEY
#  define F3_KEY 65472
# endif
# ifndef F4_KEY
#  define F4_KEY 65473
# endif
# ifndef F5_KEY
#  define F5_KEY 65474
# endif
# ifndef F6_KEY
#  define F6_KEY 65475
# endif
# ifndef F7_KEY
#  define F7_KEY 65476
# endif
# ifndef F8_KEY
#  define F8_KEY 65477
# endif
# ifndef PLUS_KEY
#  define PLUS_KEY 65451
# endif
# ifndef MINUS_KEY
#  define MINUS_KEY 65453
# endif

typedef struct three_points
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_ipoint;

typedef struct two_points
{
	float	x;
	float	y;
	int		color;
}	t_fpoint;

typedef struct s_delta
{
	float	dx;
	float	dy;
}	t_delta;

typedef struct s_env
{
	char		*map_path;
	t_ipoint	**final_tab;
	t_ipoint	*initial_points;
	t_fpoint	*final_points;
	int			x;
	int			y;
	int			map_w;
	int			map_h;
	void		*mlx;	
	void		*win;
	void		*image;
	void		*address;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	int			scale;
	int			c_y;
	int			c_x;
	int			i;
	float		altitude;
	float		iso_angle;
	int			translation_x;
	int			translation_y;
	float		zoom;
}	t_env;

//start.c
void	map_info(t_env *env);
void	check_format(t_env *env);
void	parse_map(t_env *env);
int		env_init(t_env *env);
int		render(t_env *env);
//points.c
void	three_dim_points(t_env *env);
void	two_dim_points(t_env *env);
int		min(int a, int b);
int		define_scale(t_env *env);
//fdf.c
int		error(char *error_message);
void	free_final_tab(t_env *env);
int		hex_to_int(const char *hex);
//limits.c
void	limits(t_env *env);
void	no_limit(t_env *env);
void	right_limit(t_env *env);
void	low_limit(t_env *env);
//draw.c
void	draw_line(t_env *env, t_fpoint point0, t_fpoint point1);
void	put_pixel(t_env *env, int x, int y, int color);
void	draw_background(t_env *env);
//hooks.c
void	h_management(t_env *env);
int		key_handler(int key, t_env *env);
int		close_win(t_env *env);

#endif