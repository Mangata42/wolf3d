/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:41:20 by nghaddar          #+#    #+#             */
/*   Updated: 2017/09/21 18:02:16 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		**convert_buffer(int **map, char *buffer, int x, int y)
{
	int i;
	int a;
	int b;

	if (!(map = (int **)malloc(sizeof(int *) * y + 1)))
		error();
	i = -1;
	a = -1;
	while (++a < y)
	{
		b = 0;
		map[a] = (int *)malloc(sizeof(int) * x + 1);
		while (b < x)
		{
			if (ft_isdigit(buffer[++i]) == 1)
			{
				map[a][b] = buffer[i] - 48;
				b++;
			}
		}
	}
	return (map);
}

int		**compute_size(char *buffer)
{
	int x;
	int y;
	int i;
	int **map;

	x = 0;
	y = 0;
	i = -1;
	map = NULL;
	while (buffer[++i] != '\0' && buffer[i] != '\n')
	{
		if (ft_isdigit(buffer[i]) == 1)
			x++;
	}
	i = -1;
	while (buffer[++i] != '\0')
		(buffer[i] == '\n') ? (y++) : (i += 0);
	y++;
	map = convert_buffer(map, buffer, x, y);
	return (map);
}

void	verify_buffer(char *buffer)
{
	int i;

	i = -1;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] != '\n' && buffer[i] != ' '
			&& ft_isdigit(buffer[i]) == 0)
		{
			ft_putstr("Well, sorry pal, your map is not suitable.\n");
			ft_exit();
		}
	}
}

int		**parser(int fd)
{
	char	*line;
	char	*buffer;
	int		**map;

	buffer = malloc(0);
	while ((get_next_line(fd, &line)) > 0)
	{
		buffer = ft_realloc((void **)&buffer, ft_strlen(line) + 2);
		buffer = ft_strcat(buffer, line);
		buffer = ft_strcat(buffer, "\n");
		free(line);
	}
	buffer[ft_strlen(buffer) - 1] = 0;
	verify_buffer(buffer);
	map = compute_size(buffer);
	free(buffer);
	return (map);
}

int		**open_arg(char **argv)
{
	int fd;
	int **map;

	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		error();
	map = parser(fd);
	close(fd);
	return (map);
}
