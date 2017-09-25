/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reticle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:41:22 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/25 18:47:00 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	circle_init(t_env *env, int radius)
{
	env->reticle.cirx = radius - 1;
	env->reticle.ciry = 0;
	env->reticle.cirdx = 1;
	env->reticle.cirdy = 1;
	env->reticle.cirerr = env->reticle.cirdx - (radius << 1);
}

void	draw_circle(int x0, int y0, int radius, t_env *env)
{
	circle_init(env, radius);
	while (env->reticle.cirx >= env->reticle.ciry)
	{
		ft_put_pixel(env, x0 + env->reticle.cirx, y0 + env->reticle.ciry, RET);
		ft_put_pixel(env, x0 + env->reticle.ciry, y0 + env->reticle.cirx, RET);
		ft_put_pixel(env, x0 - env->reticle.ciry, y0 + env->reticle.cirx, RET);
		ft_put_pixel(env, x0 - env->reticle.cirx, y0 + env->reticle.ciry, RET);
		ft_put_pixel(env, x0 - env->reticle.cirx, y0 - env->reticle.ciry, RET);
		ft_put_pixel(env, x0 - env->reticle.ciry, y0 - env->reticle.cirx, RET);
		ft_put_pixel(env, x0 + env->reticle.ciry, y0 - env->reticle.cirx, RET);
		ft_put_pixel(env, x0 + env->reticle.cirx, y0 - env->reticle.ciry, RET);
		if (env->reticle.cirerr <= 0)
		{
			env->reticle.ciry += 1;
			env->reticle.cirerr += env->reticle.cirdy;
			env->reticle.cirdy += 2;
		}
		if (env->reticle.cirerr > 0)
		{
			env->reticle.cirx -= 1;
			env->reticle.cirdx += 2;
			env->reticle.cirerr += (-radius << 1) + env->reticle.cirdx;
		}
	}
}
