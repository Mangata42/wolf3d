/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:53:43 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/26 14:05:08 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_exit(t_env *env)
{
	system("killall afplay");
	exit(EXIT_SUCCESS);
}

void	error(void)
{
	ft_putstr("error code: ");
	ft_putnbr(errno);
	ft_putchar('\n');
	perror("error");
	exit(EXIT_FAILURE);
}