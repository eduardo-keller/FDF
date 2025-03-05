/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:04:14 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/05 17:59:41 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FDF_H
# define FDF_H
#include <fcntl.h>
#include <stdio.h>

#define MLX_ERROR 1
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define ISO_ANGLE 0.523599
#define RED 0xFF0000
#define BLACK 0X000000

typedef struct three_points
{
	int	x;
	int	y;
	int	z;
}	t_ipoint;

typedef struct two_points
{
	float	x;
	float	y;
}	t_fpoint;

typedef struct s_delta
{
	float	dx;
	float	dy;
}	t_delta;

typedef struct s_env
{
	char		*map_path;
	int			**final_tab;
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
}	t_env;

//start.c
void	map_info(t_env *env);
void	check_format(t_env *env);
void	parse_map(t_env *env);
int		env_init(t_env *env);
int		render(t_env *env);
//points.c
void	three_dim_point(t_env *env);
void	two_dim_points(t_env *env); //changes from original. used standard iso tranformation.
//fdf.c
int		error(char *error_message);
void	free_final_tab(t_env *env);
//limits.c
void	limits(t_env *env); // c_y and c_x were originally initizalized as 1. changed to 0.
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

/*get_next_line
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
//split
char	**ft_split(char const *s, char c);
//libft
int		ft_atoi(char *ptr);*/

#endif