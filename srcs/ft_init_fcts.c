/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fcts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:04:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/25 00:35:27 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_env(t_env *env, char **argv)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WINDOW_HEIGHT, WINDOW_WIDTH,
		"le correcteur est gay");
	env->img = mlx_xpm_file_to_image(env->mlx, "./textures/space.xpm",
		&(env->text[0].width), &(env->text[0].height));
	env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl),
		&(env->end));
	env->time = 0;
	env->oldTime = 0;
	env->world_map = open_arg(argv);
	env->holygrenade.img = mlx_xpm_file_to_image(env->mlx, "./textures/holygrenade.xpm",
		&(env->holygrenade.width), &(env->holygrenade.height));
	env->holygrenade_sw = 0;
	load_chaingun(env);
}

void	ft_init_player(t_env *env)
{
	env->player.posX = 3;
	env->player.posY = 3;
	env->player.dirX = -1;
	env->player.dirY = 0;
	env->screen.planeX = 0;
	env->screen.planeY = 0.66;
}

void	ft_init_screen(t_env *env)
{
	env->screen.cameraX = 2 * env->x / (double)WINDOW_WIDTH - 1;
	env->screen.rayPosX = env->player.posX;
	env->screen.rayPosY = env->player.posY;
	env->screen.rayDirX = env->player.dirX +
		env->screen.planeX * env->screen.cameraX;
	env->screen.rayDirY = env->player.dirY
		+ env->screen.planeY * env->screen.cameraX;
}

void	ft_init_map(t_env *env)
{
	env->map.mapX = (int)env->screen.rayPosX;
	env->map.mapY = (int)env->screen.rayPosY;
	env->map.deltaDistX = sqrt(1 + (env->screen.rayDirY * env->screen.rayDirY)
		/ (env->screen.rayDirX * env->screen.rayDirX));
	env->map.deltaDistY = sqrt(1 + (env->screen.rayDirX * env->screen.rayDirX)
		/ (env->screen.rayDirY * env->screen.rayDirY));
	env->map.hit = 0;
}
