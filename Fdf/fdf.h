/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:04:14 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/02/25 17:00:07 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

# define MLX_ERROR 1
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define ISO_ANGLE 0.523599

typedef struct three_points
{
	int	x;
	int	y;
	int	z;
}	t_ipoint;

typedef struct	two_points
{
	float	x;
	float	y;
}	t_fpoint;


typedef struct s_env
{
	char	*map_path;
	int		map_w;
	int		map_h;
	int		**final_tab;
	int		x;
	int		y;
	t_ipoint	*initial_points;
	void	*mlx;
	void	*win;
	void	*image;
	void	*address;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	t_fpoint	*final_points;
	int		scale;
	float	altitude;
	float	iso_angle;
	int		c_y;
	int		c_x;
	int		i;
}	t_env;

//start.c
void	map_info(t_env *env);
void	check_format(t_env *env);
void	parse_map(t_env *env);
int	env_init(t_env *env);
//points.c
void	three_dim_point(t_env *env);
void	two_dim_points(t_env *env); //changes from original. used standard iso tranformation.
//fdf.c
int		error(char *error_message);
void	free_final_tab(t_env *env);
//limits.c
void	limits(t_env *env) // c_y and c_x were originally initizalized as 1. changed to 0.

//get_next_line
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
//split
char	**ft_split(char const *s, char c);
//libft
int		ft_atoi(char *ptr);
