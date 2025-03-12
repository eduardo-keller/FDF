/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:13:06 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/12 16:54:33 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ugly maps: 10-70, 20-60, 42 does not seem to connect properly in 2;
//
int	main(int argc, char **argv)
{
	t_env	env;

	env.map_path = argv[1];
	env.map_w = 0;
	env.map_h = 0;
	env.altitude = 1;
	//env.scale = 29;  swiss is 30
	env.iso_angle = 0.523599; // from arab dude 0.523599, from swiss 7.37
	env.translation = 1; //
	env.y = 0; //
	if (argc == 2)
	{
		map_info(&env);
		check_format(&env);
		parse_map(&env);
		three_dim_points(&env);
		env_init(&env);
	}
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