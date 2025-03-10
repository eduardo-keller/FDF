/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:12:49 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/10 15:15:58 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	h_management(t_env *env)
{
	mlx_key_hook(env->win, key_handler, env);
	mlx_hook(env->win, 17, 0, close_win, env);
}

int	key_handler(int key, t_env *env)
{
	if (key == 53)
		close_win(env);
	return(0);
}

int	close_win(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit (0);
}
