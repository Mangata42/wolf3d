/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:16:51 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/25 18:37:50 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	animate_chaingun(t_env *env)
{
	int i;

	i = 0;
	system("afplay ./music/chaingun.wav&");
	system("afplay ./music/shell.wav&");
	while (++i < 7)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->chaingun[i].img, 320
			- (env->chaingun[i].width / 2), 640 - (env->chaingun[i].height));
	}
}

void	draw_floor(t_env *env)
{
	int y;

	y = env->draw.draw_end - 1;
	while (++y < WINDOW_HEIGHT)
		ft_put_pixel(env, env->x, y, 0x1E202A);
}

int		color_choice(t_env *env)
{
	if (env->map.side == 1)
	{
		if ((env->map.step_x == -1 && env->map.step_y == -1) ||
			(env->map.step_x == 1 && env->map.step_y == -1))
			return (0x47244E);
		if ((env->map.step_x == -1 && env->map.step_y == 1) ||
			(env->map.step_x == 1 && env->map.step_y == 1))
			return (0x5E82B0);
	}
	if ((env->map.step_x == -1 && env->map.step_y == -1) ||
		(env->map.step_x == -1 && env->map.step_y == 1))
		return (0xFF595E);
	else
		return (0xFFCA3A);
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
