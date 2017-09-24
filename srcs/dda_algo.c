/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:09:27 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/24 23:36:46 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	compute_fps(t_env *env)
{
	char *fps_str;

	env->oldTime = env->time;
	env->time = clock();
	env->fps = 60 / ((double)(env->time - env->oldTime) / CLOCKS_PER_SEC);
	env->player.movSpeed = 20 *
		((double)(env->time - env->oldTime) / CLOCKS_PER_SEC);
	env->player.rotSpeed = 10 *
		((double)(env->time - env->oldTime) / CLOCKS_PER_SEC);
	fps_str = ft_itoa(env->fps);
	mlx_string_put(env->mlx, env->win, 3, 10, 0x00ff00, "FPS: ");
	mlx_string_put(env->mlx, env->win, 50, 10, 0x00ff00, fps_str);
	mlx_string_put(env->mlx, env->win, 320, 320, 0x0000ff, "X");
	free(fps_str);
}

void	ft_determine_draw(t_env *env)
{
	if (env->map.side == 0)
		env->map.perpWallDist = (env->map.mapX - env->screen.rayPosX
			+ (1 - env->map.stepX) / 2) / env->screen.rayDirX;
	else
		env->map.perpWallDist = (env->map.mapY - env->screen.rayPosY
			+ (1 - env->map.stepY) / 2) / env->screen.rayDirY;
	env->draw.lineHeight = WINDOW_HEIGHT / env->map.perpWallDist;
	env->draw.drawStart = -(env->draw.lineHeight) / 2 + WINDOW_HEIGHT / 2;
	if (env->draw.drawStart < 0)
		env->draw.drawStart = 0;
	env->draw.drawEnd = env->draw.lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (env->draw.drawEnd >= WINDOW_HEIGHT)
		env->draw.drawEnd = WINDOW_HEIGHT - 1;
	env->draw.a.x = env->x;
	env->draw.a.y = env->draw.drawStart;
	env->draw.b.x = env->x;
	env->draw.b.y = env->draw.drawEnd;
}

void	ft_ray_dir(t_env *env)
{
	if (env->screen.rayDirX < 0)
	{
		env->map.stepX = -1;
		env->map.sideDistX = (env->screen.rayPosX - env->map.mapX)
			* env->map.deltaDistX;
	}
	else
	{
		env->map.stepX = 1;
		env->map.sideDistX = (env->map.mapX + 1.0 - env->screen.rayPosX)
			* env->map.deltaDistX;
	}
	if (env->screen.rayDirY < 0)
	{
		env->map.stepY = -1;
		env->map.sideDistY = (env->screen.rayPosY - env->map.mapY)
			* env->map.deltaDistY;
	}
	else
	{
		env->map.stepY = 1;
		env->map.sideDistY = (env->map.mapY + 1.0 - env->screen.rayPosY)
			* env->map.deltaDistY;
	}
}

void	ft_ray_collision(t_env *env)
{
	while (env->map.hit == 0)
	{
		if (env->map.sideDistX < env->map.sideDistY)
		{
			env->map.sideDistX += env->map.deltaDistX;
			env->map.mapX += env->map.stepX;
			env->map.side = 0;
		}
		else
		{
			env->map.sideDistY += env->map.deltaDistY;
			env->map.mapY += env->map.stepY;
			env->map.side = 1;
		}
		if (env->world_map[env->map.mapX][env->map.mapY] > 0)
			env->map.hit = 1;
	}
}
