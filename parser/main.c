/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:41:20 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/19 17:49:48 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    compute_size()

void    parser(int fd)
{
    int     ret;
    char    *line;
    char    *buffer;

    ret = 42;
    buffer = malloc(0);
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        buffer = ft_realloc((void **)&buffer, ft_strlen(line) + 2);
        buffer = ft_strcat(buffer, line);
        buffer = ft_strcat(buffer, "\n");
        free(line);
    }
    buffer[ft_strlen(buffer) - 2] = 0;
    puts(buffer);
}

int     main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
    {
        puts("Wrong number of args");
        exit(EXIT_FAILURE);
    }
    fd = open(argv[1], O_RDONLY);
    if (!fd)
    {
        perror("open:");
        exit(EXIT_FAILURE);
    }
    parser(fd);
    while (1);
    return (0);
}