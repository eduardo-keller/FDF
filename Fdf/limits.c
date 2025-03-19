/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:11:32 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/19 16:45:39 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	limits(t_env *env)
{
	env->c_y = 1;
	env->i = 0;
	while (env->c_y < env->map_h)
	{
		env->c_x = 1;
		while (env->c_x < env->map_w)
			no_limit(env);
		if (env->c_x == env->map_w)
		{
			low_limit(env);
			env->i++;
		}
		env->c_y++;
	}
	env->c_x = 1;
	if (env->c_y == env->map_h)
	{
		while (env->c_x < env->map_w)
		{
			right_limit(env);
			env->i++;
		}
	}
	free (env->final_points);
}

void	no_limit(t_env *env)
{
	right_limit(env);
	low_limit(env);
	env->i++;
}

void	right_limit(t_env *env)
{
	t_fpoint	point0;
	t_fpoint	point1;

	point0.x = env->final_points[env->i].x;
	point0.y = env->final_points[env->i].y;
	point0.color = env->final_points[env->i].color;
	point1.x = env->final_points[env->i + 1].x;
	point1.y = env->final_points[env->i + 1].y;
	point1.color = env->final_points[env->i + 1].color;
	draw_line(env, point0, point1);
	env->c_x++;
}

void	low_limit(t_env *env)
{
	t_fpoint	point0;
	t_fpoint	point1;

	point0.x = env->final_points[env->i].x;
	point0.y = env->final_points[env->i].y;
	point0.color = env->final_points[env->i].color;
	point1.x = env->final_points[env->i + env->map_w].x;
	point1.y = env->final_points[env->i + env->map_w].y;
	point1.color = env->final_points[env->i + env->map_w].color;
	draw_line(env, point0, point1);
}
