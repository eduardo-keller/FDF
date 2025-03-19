/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:12:49 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/19 17:31:08 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	h_management(t_env *env)
{
	mlx_key_hook(env->win, key_handler, env);
	mlx_hook(env->win, 17, 0, close_win, env);
	mlx_hook(env->win, 2, 1, key_handler, env);
}

int	key_handler(int key, t_env *env)
{
	if (key == ESC_KEY)
		close_win(env);
	else if (key == UP_KEY)
		env->translation_y -= TRANS_FACTOR_Y;
	else if (key == DOWN_KEY)
	env->translation_y += TRANS_FACTOR_Y;
	else if (key == LEFT_KEY)
		env->translation_x -= TRANS_FACTOR_X;
	else if (key == RIGHT_KEY)
		env->translation_x += TRANS_FACTOR_X;
	else if (key == F1_KEY)
		env->iso_angle += 0.01;
	else if (key == F2_KEY)
		env->iso_angle -= 0.01;
	else if (key == PLUS_KEY)
		env->scale += 1;
	else if (key == MINUS_KEY)
		env->scale -= 1;
	else if (key == F3_KEY)
		env->altitude += 0.1;
	else if (key == F4_KEY)
		env->altitude -= 0.1;
	return (0);
}

int	close_win(t_env *env)
{
	if (env->image)
		mlx_destroy_image(env->mlx, env->image);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
		mlx_destroy_display(env->mlx);
	free(env->mlx);
	if (env->initial_points)
	{
		free(env->initial_points);
		env->initial_points = NULL;
	}
	exit (0);
}
