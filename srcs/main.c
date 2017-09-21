/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:27:45 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/21 18:35:18 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_floor(t_env *env)
{
	int y;

	y = env->draw.drawEnd - 1;
	while (++y < WINDOW_HEIGHT)
		ft_put_pixel(env, env->x, y, 0xf4a442);
}

int		loop_hook(t_env *env)
{
	ft_movements(env);
	env->time = clock();
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_xpm_file_to_image(env->mlx, "./textures/space.xpm",
		&(env->text[0].width), &(env->text[0].height));
	env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl),
			&(env->end));
	env->x = 0;
	while (env->x < WINDOW_WIDTH)
	{
		ft_init_screen(env);
		ft_init_map(env);
		ft_ray_dir(env);
		ft_ray_collision(env);
		ft_determine_draw(env);
		env->draw.color = color_choice(env);
		ft_line(env, env->draw.a, env->draw.b, env->draw.color);
		draw_floor(env);
		env->x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	compute_fps(env);
	return (0);
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
