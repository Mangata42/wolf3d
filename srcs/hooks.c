/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:22:38 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/26 15:44:32 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	refresh_screen(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->chaingun[0].img, 320
		- (env->chaingun[0].width / 2), 640 - (env->chaingun[0].height));
}

int		loop_hook(t_env *env)
{
	ft_movements(env);
	env->time = clock();
	mlx_destroy_image(env->mlx, env->img);
	load_textures(env);
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
	draw_circle(320, 320, 10, env);
	refresh_screen(env);
	compute_fps(env);
	return (0);
}

int		keypress_hook(int keycode, t_env *env)
{
	if (keycode == K_ESC)
		ft_exit();
	if (keycode == K_SPA)
		animate_chaingun(env);
	if (keycode == K_UP)
		env->keyb.k_up = 1;
	if (keycode == K_DOWN)
		env->keyb.k_down = 1;
	if (keycode == K_RIGHT)
		env->keyb.k_right = 1;
	if (keycode == K_LEFT)
		env->keyb.k_left = 1;
	return (0);
}

int		keyrelease_hook(int keycode, t_env *env)
{
	if (keycode == K_UP)
		env->keyb.k_up = 0;
	if (keycode == K_DOWN)
		env->keyb.k_down = 0;
	if (keycode == K_RIGHT)
		env->keyb.k_right = 0;
	if (keycode == K_LEFT)
		env->keyb.k_left = 0;
	return (0);
}
