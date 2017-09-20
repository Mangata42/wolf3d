/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:41:20 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/20 21:07:52 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int     **convert_buffer(int **map, char *buffer, int x, int y)
{
    int i;

    if (!(map = (int **)malloc(sizeof(int) * y)))
    {
        perror("Can't malloc");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < y)
    {
        if (!(map[i] = (int *)malloc(sizeof(int) * x)))
        {
            perror("Can't malloc");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    for (int a = 0; a < y; a++)
    {
        for (int b = 0; b < x; b++)
            map[a][b] = 24;
    }
    return (map);
}

int    **compute_size(char *buffer)
{
   int x;
   int y;
   int i;
   int  **map;

   x = 0;
   y = 0;
   i = 0;
   while (buffer[i] != '\0' && buffer[i] != '\n')
   {
       if (ft_isdigit(buffer[i]) == 1)
            x++;
        i++;
   }
    i = 0;
    while (buffer[i] != '\0')
    {
        (buffer[i] == '\n') ? (y++) : (i=i);
        i++;
    }
    y++;
    map = convert_buffer(map, buffer, x, y);
    // for (int a = 0; a < y; a++)
    // {
    //     for (int b = 0; b < x; b++)
    //         printf("%d ", map[a][b]);
    //     puts("\n");
    // }
    return (map);
}

void    parser(int fd)
{
    char    *line;
    char    *buffer;
    int     **map;

    buffer = malloc(0);
    while ((get_next_line(fd, &line)) > 0)
    {
        buffer = ft_realloc((void **)&buffer, ft_strlen(line) + 2);
        buffer = ft_strcat(buffer, line);
        buffer = ft_strcat(buffer, "\n");
        free(line);
    }
    buffer[ft_strlen(buffer) - 1] = 0;
    // puts(buffer);
    map = compute_size(buffer);
    free(buffer);
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
    return (0);
}