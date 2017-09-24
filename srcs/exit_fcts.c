/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:53:43 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/25 01:28:07 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_exit(t_env *env)
{
	int y;

	y = -1;
	while (++y < env->map_w)
		free(env->world_map[y]);
	free(env->world_map);
	system("killall afplay");
	exit(EXIT_SUCCESS);
}

void	error(void)
{
	perror("error");
	system("killall afplay");
	exit(EXIT_FAILURE);
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

void	holy_grenade(t_env *env)
{
	ft_exit(env);
}