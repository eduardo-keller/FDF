/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:38:52 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/18 17:02:46 by ekeller-@st      ###   ########.fr       */
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
			env->initial_points[i] = (t_ipoint){env->x,
				env->y, env->final_tab[env->y][env->x].z,
				env->final_tab[env->y][env->x].color};
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
	if (!env->final_points)
		error("Malloc failed");
	while (i < (env->map_w * env->map_h))
	{
		z = env->initial_points[i].z * env->altitude;
		env->final_points[i].y = -z + (env->initial_points[i].x
				+ env->initial_points[i].y) * sin(env->iso_angle);
		env->final_points[i].x = (env->initial_points[i].x
				- env->initial_points[i].y) * cos(env->iso_angle);
		env->final_points[i].y *= env->scale;
		env->final_points[i].x *= env->scale;
		env->final_points[i].color = env->initial_points[i].color;
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
	float	max_dimension;

	max_dimension = fmaxf(env->map_w, env->map_h);
	env->scale = fminf(WINDOW_WIDTH, WINDOW_HEIGHT) / max_dimension * 0.7;
	return (1);
}
