/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:22:38 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/18 16:32:17 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void    error()
{
    perror("error: ");
    exit(EXIT_FAILURE);
}

int    ft_destroy(t_env *env)
{
    if (1)
    {
        system("killall afplay");
        exit(EXIT_SUCCESS);
    }
    return (0);
}