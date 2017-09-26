/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:53:43 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/26 15:44:04 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_exit(void)
{
	system("killall afplay");
	exit(EXIT_SUCCESS);
	return (0);
}

void	error(void)
{
	ft_putstr("error code: ");
	ft_putnbr(errno);
	ft_putchar('\n');
	perror("error");
	exit(EXIT_FAILURE);
}
