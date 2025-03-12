/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:21:57 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/12 17:52:57 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	draw_line(t_env *env, t_fpoint point0, t_fpoint point1)
{
	float	step;
	float	x;
	float	y;
	t_delta	delta;
	int		i;

	i = 0;
	delta.dx = point1.x - point0.x;
	delta.dy = point1.y - point0.y;
	if (fabsf(delta.dx) >= fabsf(delta.dy))
		step = fabsf(delta.dx);
	else
		step = fabsf(delta.dy);
	delta.dx = delta.dx / step;
	delta.dy = delta.dy / step;
	x = point0.x;
	y = point0.y;
	while (i < step)
	{
		put_pixel(env, x + WINDOW_WIDTH / 2, y + WINDOW_HEIGHT / 2, RED);
		x = x + delta.dx;
		y = y + delta.dy;
		i++;
	}
}

void	put_pixel(t_env *env, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pxl = env->address +(y * env->line_lenght
				+ x * (env->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

void	draw_background(t_env *env)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h <= WINDOW_HEIGHT)
	{
		w = 0;
		while (w <= WINDOW_WIDTH)
		{
			put_pixel(env, w, h, BLACK);
			w++;
		}
		h++;
	}
}