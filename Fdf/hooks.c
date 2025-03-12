/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:12:49 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/12 15:02:02 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// void	h_management(t_env *env)
// {
// 	mlx_key_hook(env->win, key_handler, env);
// 	mlx_hook(env->win, 17, 0, close_win, env);
// }

// int	key_handler(int key, t_env *env)
// {
// 	ft_printf("the key is:%i", key); // - is 65453; + is 65451; left is 65361; right is 65363;
// 	if (key == 65307) // changed key from 53 to 65307
// 		close_win(env);
// 	return(0);
// }

// int	close_win(t_env *env)
// {
// 	mlx_destroy_window(env->mlx, env->win);
// 	exit (0);
// }

void	h_management(t_env *env)
{
	mlx_key_hook(env->win, key_handler, env);
	mlx_hook(env->win, 17, 0, close_win, env);
	mlx_hook(env->win, 4, 0, mouse_handler, env);
	mlx_hook(env->win, 2, 1L << 0, key_handler, env);
}

int	key_handler(int key, t_env *env)
{
	//ft_printf("the key is:%i", key);
	if (key == 65307)
		close_win(env);
	else if (key == 13 || key == 126)
		env->translation -= TRANS_FACTOR_X;
	else if (key == 1 || key == 125)
		env->translation += TRANS_FACTOR_X;
	else if (key == 65363 || key == 123)
		env->iso_angle += 0.01;
	else if (key == 65361 || key == 124)
		env->iso_angle -= 0.01;
	else if (key == 65451)
		env->altitude += ALTITUDE;
	else if (key == 65453)
		env->altitude -= ALTITUDE;
	return (0);
}

int	close_win(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit (0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	(void) x;
	(void) y;
	if (mousecode == 4)
		env->scale *= ZOOM_FACTOR;
	else if (mousecode == 5)
		env->scale /= ZOOM_FACTOR;
	return (0);
}