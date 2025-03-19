/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:12:22 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/19 16:46:02 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_error(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		free(line);
	close(fd);
	error("Wrong map format");
}

void	map_info(t_env *env)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(env->map_path, O_RDONLY);
	if (fd < 0)
		error("Map error!");
	line = get_next_line(fd);
	if (!line)
		error("Map empty!");
	tab = ft_split(line, ' ');
	while (tab[env->map_w])
	{
		free(tab[env->map_w]);
		env->map_w++;
	}
	while (line)
	{
		free(line);
		env->map_h++;
		line = get_next_line(fd);
	}
	free(line);
	free(tab);
	close (fd);
}

void	check_format(t_env *env)
{
	int		fd;
	int		x;
	char	*line;
	char	**tab;

	fd = open(env->map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line);
		x = 0;
		while (tab[x])
		{
			free(tab[x]);
			x++;
		}
		free(tab);
		if (x != env->map_w)
			handle_error(fd);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

static void	parse_line(t_env *env, char **line_tab)
{
	char	**z_color;

	env->x = -1;
	while (++env->x < env->map_w)
	{
		z_color = ft_split(line_tab[env->x], ',');
		if (z_color[0] && z_color[1])
		{
			env->final_tab[env->y][env->x].z = ft_atoi(z_color[0]);
			env->final_tab[env->y][env->x].color = hex_to_int(z_color[1] + 2);
			free(z_color[0]);
			free(z_color[1]);
		}
		else
		{
			env->final_tab[env->y][env->x].z = ft_atoi(line_tab[env->x]);
			env->final_tab[env->y][env->x].color = COLOR;
			if (z_color[0])
				free(z_color[0]);
		}
		free(z_color);
		free(line_tab[env->x]);
	}
}

void	parse_map(t_env *env)
{
	char	**line_tab;
	char	*line;
	int		fd;

	fd = open(env->map_path, O_RDONLY);
	env->final_tab = malloc(sizeof(t_ipoint *) * env->map_h);
	if (!env->final_tab)
		error("Malloc failed");
	while (env->y < env->map_h)
	{
		env->final_tab[env->y] = malloc(sizeof(t_ipoint) * env->map_w);
		if (!env->final_tab[env->y])
			error("Malloc failed");
		line = get_next_line(fd);
		line_tab = ft_split(line, ' ');
		free(line);
		parse_line(env, line_tab);
		env->y++;
		free(line_tab);
	}
	line = get_next_line(fd);
	if (line)
		free(line);
	close(fd);
}
