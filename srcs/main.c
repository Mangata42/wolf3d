/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:27:45 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/25 00:35:05 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	load_chaingun(t_env *env)
{
	env->chaingun[1].img = mlx_xpm_file_to_image(env->mlx, "./textures/chaingun/0.xpm",
		&(env->chaingun[1].width), &(env->chaingun[1].height));
	env->chaingun[2].img = mlx_xpm_file_to_image(env->mlx, "./textures/chaingun/1.xpm",
		&(env->chaingun[2].width), &(env->chaingun[2].height));
	env->chaingun[3].img = mlx_xpm_file_to_image(env->mlx, "./textures/chaingun/2.xpm",
		&(env->chaingun[3].width), &(env->chaingun[3].height));
	env->chaingun[4].img = mlx_xpm_file_to_image(env->mlx, "./textures/chaingun/3.xpm",
		&(env->chaingun[4].width), &(env->chaingun[4].height));
	env->chaingun[5].img = mlx_xpm_file_to_image(env->mlx, "./textures/chaingun/4.xpm",
		&(env->chaingun[5].width), &(env->chaingun[5].height));
	env->chaingun[6].img = mlx_xpm_file_to_image(env->mlx, "./textures/chaingun/5.xpm",
		&(env->chaingun[6].width), &(env->chaingun[6].height));
	env->chaingun[7].img = mlx_xpm_file_to_image(env->mlx, "./textures/chaingun/6.xpm",
		&(env->chaingun[7].width), &(env->chaingun[7].height));
}

void	load_textures(t_env *env)
{
	env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl),
		&(env->end));
	env->img = mlx_xpm_file_to_image(env->mlx, "./textures/space.xpm",
		&(env->text[0].width), &(env->text[0].height));
	env->chaingun[0].img = mlx_xpm_file_to_image(env->mlx, "./textures/chaingun/12.xpm",
		&(env->chaingun[0].width), &(env->chaingun[0].height));
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
	{
		ft_putstr("I need the map for fucks sake, why do you expect?\n");
		ft_putstr("usage: ./wolf3d [map]\n");
		exit(EXIT_FAILURE);
	}
	init_env(&env, argv);
	// system("afplay ./music/ingame.mp3&");
	ft_init_player(&env);
	mlx_hook(env.win, KeyPress, KeyPressMask, keypress_hook, &env);
	mlx_hook(env.win, KeyRelease, KeyReleaseMask, keyrelease_hook, &env);
	mlx_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (EXIT_SUCCESS);
}
