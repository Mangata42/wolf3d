/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:09:27 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/26 11:49:57 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	compute_fps(t_env *env)
{
	char *fps_str;

	env->old_time = env->time;
	env->time = clock();
	env->fps = 60 / ((double)(env->time - env->old_time) / CLOCKS_PER_SEC);
	env->player.movspeed = 10 *
		((double)(env->time - env->old_time) / CLOCKS_PER_SEC);
	env->player.rotspeed = 5 *
		((double)(env->time - env->old_time) / CLOCKS_PER_SEC);
	fps_str = ft_itoa(env->fps);
	mlx_string_put(env->mlx, env->win, 3, 10, 0x00ff00, "FPS: ");
	mlx_string_put(env->mlx, env->win, 50, 10, 0x00ff00, fps_str);
	free(fps_str);
}

void	ft_determine_draw(t_env *env)
{
	if (env->map.side == 0)
		env->map.perpwalldist = (env->map.map_x - env->screen.raypos_x
			+ (1 - env->map.step_x) / 2) / env->screen.raydir_x;
	else
		env->map.perpwalldist = (env->map.map_y - env->screen.raypos_y
			+ (1 - env->map.step_y) / 2) / env->screen.raydir_y;
	env->draw.line_height = WINDOW_HEIGHT / env->map.perpwalldist;
	env->draw.draw_start = -(env->draw.line_height) / 2 + WINDOW_HEIGHT / 2;
	if (env->draw.draw_start < 0)
		env->draw.draw_start = 0;
	env->draw.draw_end = env->draw.line_height / 2 + WINDOW_HEIGHT / 2;
	if (env->draw.draw_end >= WINDOW_HEIGHT)
		env->draw.draw_end = WINDOW_HEIGHT - 1;
	env->draw.a.x = env->x;
	env->draw.a.y = env->draw.draw_start;
	env->draw.b.x = env->x;
	env->draw.b.y = env->draw.draw_end;
}

void	ft_ray_dir(t_env *env)
{
	if (env->screen.raydir_x < 0)
	{
		env->map.step_x = -1;
		env->map.sidedist_x = (env->screen.raypos_x - env->map.map_x)
			* env->map.deltadist_x;
	}
	else
	{
		env->map.step_x = 1;
		env->map.sidedist_x = (env->map.map_x + 1.0 - env->screen.raypos_x)
			* env->map.deltadist_x;
	}
	if (env->screen.raydir_y < 0)
	{
		env->map.step_y = -1;
		env->map.sidedist_y = (env->screen.raypos_y - env->map.map_y)
			* env->map.deltadist_y;
	}
	else
	{
		env->map.step_y = 1;
		env->map.sidedist_y = (env->map.map_y + 1.0 - env->screen.raypos_y)
			* env->map.deltadist_y;
	}
}

void	ft_ray_collision(t_env *env)
{
	while (env->map.hit == 0)
	{
		if (env->map.sidedist_x < env->map.sidedist_y)
		{
			env->map.sidedist_x += env->map.deltadist_x;
			env->map.map_x += env->map.step_x;
			env->map.side = 0;
		}
		else
		{
			env->map.sidedist_y += env->map.deltadist_y;
			env->map.map_y += env->map.step_y;
			env->map.side = 1;
		}
		if (env->world_map[env->map.map_x][env->map.map_y] > 0)
			env->map.hit = 1;
	}
}
