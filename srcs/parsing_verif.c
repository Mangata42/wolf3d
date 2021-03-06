/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:15:45 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/26 16:07:58 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	verify_limits(t_env *env)
{
	int x;
	int y;

	y = -1;
	while (++y < env->map_h)
	{
		x = -1;
		while (++x < env->map_w)
			if (env->world_map[y][x] <= 0)
				if ((x == 0 || x >= env->map_w - 1) ||
					(y == 0 || y >= env->map_h - 1))
				{
					ft_putstr("No walls around the map or x off boundaries.\n");
					errno = 0;
					error();
				}
	}
}
