/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:38:52 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/12 18:10:54 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	three_dim_points(t_env *env)
{
	int	i;

	i = 0;
	env->initial_points = malloc(env->map_h * env->map_w * sizeof(t_ipoint));
	if (!env->initial_points)
		error("Malloc failed");
	env->y = 0;
	while (env->y < env->map_h)
	{
		env->x = 0;
		while (env->x < env->map_w)
		{
			env->initial_points[i] = (t_ipoint){env->x, env->y, env->final_tab[env->y][env->x]};
			i++;
			env->x++;
		}
		env->y++;
	}
	free_final_tab(env);
}

void	two_dim_points(t_env *env)
{
	int	i;
	int	z;

	i = 0;
	env->final_points = malloc(sizeof(t_fpoint) * env->map_h * env->map_w);
	if(!env->final_points)
		error("Malloc failed");
	while (i < (env->map_w * env->map_h))
	{
		z = env->initial_points[i].z * env->altitude;
		env->final_points[i].y = -z + (env->initial_points[i].x + env->initial_points[i].y) * sin(env->iso_angle);
		env->final_points[i].x = (env->initial_points[i].x - env->initial_points[i].y) * cos(env->iso_angle);
		env->final_points[i].y *= env->scale;
		env->final_points[i].x *= env->scale;
		i++;
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	define_scale(t_env *env)
{
	int	scale_x;
	int	scale_y;
	
	scale_x = WINDOW_WIDTH / env->map_w;
	scale_y = WINDOW_HEIGHT / env->map_h;
	env->scale = min(scale_x, scale_y);
	if (env->scale < 4)
		return (1);
	env->scale /= 3;
	return (1); 
}

/*Fill in the two-dimensional table*/
// void	two_dim_points(t_env *env)
// {
// 	int	i;

// 	i = 0;
// 	env->final_points = malloc(env->map_h * env->map_w * (sizeof(t_fpoint)));
// 	if (!env->final_points)
// 		error("Malloc failed");
// 	while (i < (env->map_w * env->map_h))
// 	{
// 		env->final_points[i].y = env->initial_points[i].y \
// 				* cosf(env->iso_angle) + env->initial_points[i].y \
// 				* cosf(env->iso_angle + 2) \
// 				+ (env->initial_points[i].z * env->altitude) \
// 				* cosf(env->iso_angle - 2);
// 		env->final_points[i].x = env->initial_points[i].x \
// 				* sinf(env->iso_angle) + env->initial_points[i].y \
// 				* sinf(env->iso_angle + 2) \
// 				+ (env->initial_points[i].z * env->altitude) \
// 				* sinf(env->iso_angle - 2);
// 		env->final_points[i].x *= -env->scale;
// 		env->final_points[i].y *= env->scale;
// 		i++;
// 	}
// }