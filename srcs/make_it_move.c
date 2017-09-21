/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_it_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:12:44 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/21 18:13:55 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	key_up(t_env *env)
{
	if (!(env->world_map[(int)(env->player.posX + env->player.dirX
		* env->player.movSpeed)][(int)(env->player.posY)]))
		env->player.posX += env->player.dirX * env->player.movSpeed;
	if (!(env->world_map[(int)(env->player.posX)][(int)(env->player.posY
		+ env->player.dirY * env->player.movSpeed)]))
		env->player.posY += env->player.dirY * env->player.movSpeed;
}

void	key_down(t_env *env)
{
	if (!(env->world_map[(int)(env->player.posX - env->player.dirX
		* env->player.movSpeed)][(int)(env->player.posY)]))
		env->player.posX -= env->player.dirX * env->player.movSpeed;
	if (!(env->world_map[(int)(env->player.posX)][(int)(env->player.posY
		- env->player.dirY * env->player.movSpeed)]))
		env->player.posY -= env->player.dirY * env->player.movSpeed;
}

void	key_right(t_env *env)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = env->player.dirX;
	old_plane_x = env->screen.planeX;
	env->player.dirX = env->player.dirX * cos(-(env->player.rotSpeed))
		- env->player.dirY * sin(-(env->player.rotSpeed));
	env->player.dirY = old_dir_x * sin(-(env->player.rotSpeed))
		+ env->player.dirY * cos(-(env->player.rotSpeed));
	env->screen.planeX = env->screen.planeX * cos(-(env->player.rotSpeed))
		- env->screen.planeY * sin(-(env->player.rotSpeed));
	env->screen.planeY = old_plane_x * sin(-(env->player.rotSpeed))
		+ env->screen.planeY * cos(-(env->player.rotSpeed));
}

void	key_left(t_env *env)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = env->player.dirX;
	old_plane_x = env->screen.planeX;
	env->player.dirX = env->player.dirX * cos((env->player.rotSpeed))
		- env->player.dirY * sin((env->player.rotSpeed));
	env->player.dirY = old_dir_x * sin((env->player.rotSpeed))
		+ env->player.dirY * cos(-(env->player.rotSpeed));
	env->screen.planeX = env->screen.planeX * cos((env->player.rotSpeed))
		- env->screen.planeY * sin((env->player.rotSpeed));
	env->screen.planeY = old_plane_x * sin((env->player.rotSpeed))
		+ env->screen.planeY * cos((env->player.rotSpeed));
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
