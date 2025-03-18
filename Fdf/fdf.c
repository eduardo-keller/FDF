/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:13:06 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/18 16:52:49 by ekeller-@st      ###   ########.fr       */
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