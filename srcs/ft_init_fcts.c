/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fcts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:04:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/26 11:43:40 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_env(t_env *env, char **argv)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WINDOW_HEIGHT, WINDOW_WIDTH,
		"bonjour monsieur");
	env->img = mlx_xpm_file_to_image(env->mlx, "./textures/space.xpm",
		&(env->text[0].width), &(env->text[0].height));
	env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl),
		&(env->end));
	env->time = 0;
	env->old_time = 0;
	env->world_map = open_arg(env, argv);
	verify_limits(env);
	load_chaingun(env);
}

void	check_x(t_env *env, int ***map, int x, int y)
{
	*(map[y][x]) = 0;
	env->player.pos_x = x;
	env->player.pos_y = y;
}

void	ft_init_player(t_env *env)
{
	env->player.dir_x = -1;
	env->player.dir_y = 0;
	env->screen.plane_x = 0;
	env->screen.plane_y = 0.66;
}

void	ft_init_screen(t_env *env)
{
	env->screen.camera_x = 2 * env->x / (double)WINDOW_WIDTH - 1;
	env->screen.raypos_x = env->player.pos_x;
	env->screen.raypos_y = env->player.pos_y;
	env->screen.raydir_x = env->player.dir_x +
		env->screen.plane_x * env->screen.camera_x;
	env->screen.raydir_y = env->player.dir_y
		+ env->screen.plane_y * env->screen.camera_x;
}

void	ft_init_map(t_env *env)
{
	env->map.map_x = (int)env->screen.raypos_x;
	env->map.map_y = (int)env->screen.raypos_y;
	env->map.deltadist_x = sqrt(1 + (env->screen.raydir_y
		* env->screen.raydir_y)
		/ (env->screen.raydir_x * env->screen.raydir_x));
	env->map.deltadist_y = sqrt(1 + (env->screen.raydir_x
		* env->screen.raydir_x)
		/ (env->screen.raydir_y * env->screen.raydir_y));
	env->map.hit = 0;
}
