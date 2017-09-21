/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:22:38 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/21 18:13:58 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_exit(void)
{
	system("killall afplay");
	exit(EXIT_SUCCESS);
}

void	error(void)
{
	perror("error");
	ft_exit();
}

int		ft_destroy(void)
{
	if (1)
	{
		system("killall afplay");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		keypress_hook(int keycode, t_env *env)
{
	if (keycode == 18)
	{
		system("afplay ./music/nuke.mp3");
		exit(EXIT_SUCCESS);
	}
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == K_SPA)
		system("afplay ./music/9mm.wav&");
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
