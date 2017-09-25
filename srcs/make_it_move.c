/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_it_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:12:44 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/25 18:41:47 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	key_up(t_env *env)
{
	if (!(env->world_map[(int)(env->player.pos_x + env->player.dir_x
		* env->player.movspeed)][(int)(env->player.pos_y)]))
		env->player.pos_x += env->player.dir_x * env->player.movspeed;
	if (!(env->world_map[(int)(env->player.pos_x)][(int)(env->player.pos_y
		+ env->player.dir_y * env->player.movspeed)]))
		env->player.pos_y += env->player.dir_y * env->player.movspeed;
}

void	key_down(t_env *env)
{
	if (!(env->world_map[(int)(env->player.pos_x - env->player.dir_x
		* env->player.movspeed)][(int)(env->player.pos_y)]))
		env->player.pos_x -= env->player.dir_x * env->player.movspeed;
	if (!(env->world_map[(int)(env->player.pos_x)][(int)(env->player.pos_y
		- env->player.dir_y * env->player.movspeed)]))
		env->player.pos_y -= env->player.dir_y * env->player.movspeed;
}

void	key_right(t_env *env)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = env->player.dir_x;
	old_plane_x = env->screen.plane_x;
	env->player.dir_x = env->player.dir_x * cos(-(env->player.rotspeed))
		- env->player.dir_y * sin(-(env->player.rotspeed));
	env->player.dir_y = old_dir_x * sin(-(env->player.rotspeed))
		+ env->player.dir_y * cos(-(env->player.rotspeed));
	env->screen.plane_x = env->screen.plane_x * cos(-(env->player.rotspeed))
		- env->screen.plane_y * sin(-(env->player.rotspeed));
	env->screen.plane_y = old_plane_x * sin(-(env->player.rotspeed))
		+ env->screen.plane_y * cos(-(env->player.rotspeed));
}

void	key_left(t_env *env)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = env->player.dir_x;
	old_plane_x = env->screen.plane_x;
	env->player.dir_x = env->player.dir_x * cos((env->player.rotspeed))
		- env->player.dir_y * sin((env->player.rotspeed));
	env->player.dir_y = old_dir_x * sin((env->player.rotspeed))
		+ env->player.dir_y * cos(-(env->player.rotspeed));
	env->screen.plane_x = env->screen.plane_x * cos((env->player.rotspeed))
		- env->screen.plane_y * sin((env->player.rotspeed));
	env->screen.plane_y = old_plane_x * sin((env->player.rotspeed))
		+ env->screen.plane_y * cos((env->player.rotspeed));
}

void	ft_movements(t_env *env)
{
	if (env->keyb.k_up == 1)
		key_up(env);
	if (env->keyb.k_down == 1)
		key_down(env);
	if (env->keyb.k_right == 1)
		key_right(env);
	if (env->keyb.k_left == 1)
		key_left(env);
}
