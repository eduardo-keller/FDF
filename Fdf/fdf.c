/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:13:06 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/19 16:45:18 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	env.map_path = argv[1];
	env.map_w = 0;
	env.map_h = 0;
	env.altitude = 1;
	env.iso_angle = 0.523599;
	env.translation_y = 1;
	env.translation_x = 1;
	env.y = 0;
	if (argc == 2)
	{
		map_info(&env);
		check_format(&env);
		parse_map(&env);
		three_dim_points(&env);
		define_scale(&env);
		env_init(&env);
	}
	else
		error("error");
}

int	env_init(t_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		free(env->mlx);
		return (MLX_ERROR);
	}
	env->win = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (env->win == NULL)
		return (MLX_ERROR);
	env->image = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env->address = mlx_get_data_addr(env->image, &env->bits_per_pixel,
			&env->line_lenght, &env->endian);
	two_dim_points(env);
	limits(env);
	h_management(env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	return (0);
}

int	error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}

void	free_final_tab(t_env *env)
{
	int	y;

	y = 0;
	while (y < env->map_h)
	{
		free(env->final_tab[y]);
		y++;
	}
	free(env->final_tab);
}

int	hex_to_int(const char *hex)
{
	int		value;
	char	c;

	value = 0;
	while (*hex)
	{
		c = *hex++;
		value <<= 4;
		if (c >= '0' && c <= '9')
			value += c - '0';
		else if (c >= 'a' && c <= 'f')
			value += c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			value += c - 'A' + 10;
	}
	return (value);
}
