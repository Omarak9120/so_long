/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:00:05 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/08 16:29:47 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_visited_array(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size_x)
	{
		j = 0;
		while (j < map->size_y)
		{
			map->visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int	**allocate_2d_array(int rows, int cols)
{
	int	**array;
	int	i;

	array = malloc(sizeof(int *) * rows);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = malloc(sizeof(int) * cols);
		if (array[i] == NULL)
		{
			while (i > 0)
				free(array[--i]);
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

void	malloc_tab_visited(t_map *map)
{
	map->tab = allocate_2d_array(map->size_x, map->size_y);
	if (map->tab == NULL)
		exit_error(map, "ERROR: Memory allocation failed for tab.");
	map->visited = allocate_2d_array(map->size_x, map->size_y);
	if (map->visited == NULL)
	{
		free(map->tab);
		exit_error(map, "ERROR: Memory allocation failed for visited.");
	}
	init_visited_array(map);
}

void	read_map(const char *filename, t_map *map)
{
	int		i;
	char	*line;
	int		fd;
	int		j;

	i = 0;
	map->error = 0;
	map->exit_count = 0;
	map->player_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error(map, "ERROR: Could not open map file.");
	malloc_tab_visited(map);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		loop_read(map, line, i, j);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	handle_error(map, fd, i);
	close(fd);
}
