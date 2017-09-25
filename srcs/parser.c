/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:59:24 by Mangata           #+#    #+#             */
/*   Updated: 2017/09/25 23:14:45 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		**convert_buffer(t_env *env, int **map, char *buffer)
{
	int i;
	int a;
	int b;

	if (!(map = (int **)malloc(sizeof(int *) * env->map_h + 1)))
		error();
	i = -1;
	a = -1;
	while (++a < env->map_h)
	{
		b = 0;
		map[a] = (int *)malloc(sizeof(int) * env->map_w + 1);
		while (b < env->map_w)
		{
			if (ft_isdigit(buffer[++i]) == 1 || buffer[i] == 'x')
			{
				map[a][b] = buffer[i] - 48;
				(buffer[i] == 'x') ? (map[a][b] = 0) : (1);
				b++;
			}
		}
	}
	return (map);
}

int		**compute_size(t_env *env, char *buffer)
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
		if (ft_isdigit(buffer[i]) == 1 || buffer[i] == 'x')
			x++;
	i = -1;
	while (buffer[++i] != '\0')
		(buffer[i] == '\n') ? (y++) : (i += 0);
	env->map_h = y + 1;
	env->map_w = x;
	map = convert_buffer(env, map, buffer);
	return (map);
}

void	verify_buffer(char *buffer)
{
	int i;
	int	pl_x;

	i = -1;
	pl_x = 0;
	while (buffer[++i] != '\0')
	{
		(buffer[i] == 'x') ? (pl_x++) : (1);
		if (buffer[i] != '\n' && buffer[i] != ' ' && buffer[i] != 'x'
			&& ft_isdigit(buffer[i]) == 0)
		{
			errno = 22;
			ft_putstr("Well, sorry pal, your map is not suitable.\n");
			error();
		}
	}
	if (pl_x <= 0 || pl_x > 1)
	{
		ft_putstr("No x in map or too much x. Can't initiate.\n");
		errno = 1;
		error();
	}
}

int		**parser(t_env *env, int fd)
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
	free(line);
	buffer[ft_strlen(buffer) - 1] = 0;
	verify_buffer(buffer);
	map = compute_size(env, buffer);
	free(buffer);
	return (map);
}

int		**open_arg(t_env *env, char **argv)
{
	int fd;
	int **map;

	if ((fd = open(argv[1], O_RDONLY)) <= 0)
	{
		errno = 2;
		error();
	}
	map = parser(env, fd);
	close(fd);
	return (map);
}
