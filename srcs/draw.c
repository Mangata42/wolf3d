/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:16:51 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/21 18:12:06 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		color_choice(t_env *env)
{
	if (env->map.side == 1)
	{
		if ((env->map.stepX == -1 && env->map.stepY == -1) ||
			(env->map.stepX == 1 && env->map.stepY == -1))
			return (0xF7FE2E);
		if ((env->map.stepX == -1 && env->map.stepY == 1) ||
			(env->map.stepX == 1 && env->map.stepY == 1))
			return (0xff0000);
	}
	if ((env->map.stepX == -1 && env->map.stepY == -1) ||
		(env->map.stepX == -1 && env->map.stepY == 1))
		return (0x00ff00);
	else
		return (0xffffff);
}

void	ft_put_pixel(t_env *env, int x, int y, int color)
{
	int		pos;
	int8_t	mask;

	if ((x >= 0 && x <= WINDOW_HEIGHT) && (y >= 0 && y <= WINDOW_WIDTH))
	{
		pos = (y * env->sl + x * 4);
		mask = color;
		env->img_datas[pos] = mask;
		color = color >> 8;
		mask = color;
		env->img_datas[pos + 1] = mask;
		color = color >> 8;
		mask = color;
		env->img_datas[pos + 2] = mask;
		env->img_datas[pos + 3] = 0x00;
	}
}

void	ft_line(t_env *env, t_coords a, t_coords b, int color)
{
	t_line line;

	line.dx = ft_abs(b.x - a.x);
	line.sx = a.x < b.x ? 1 : -1;
	line.dy = ft_abs(b.y - a.y);
	line.sy = a.y < b.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -(line.dy)) / 2;
	while (1)
	{
		if ((a.x < WINDOW_HEIGHT && a.y < WINDOW_WIDTH) && (a.x > 0 && a.y > 0))
			ft_put_pixel(env, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		line.e2 = line.err;
		if (line.e2 > -(line.dx))
		{
			line.err -= line.dy;
			a.x += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			a.y += line.sy;
		}
	}
}
