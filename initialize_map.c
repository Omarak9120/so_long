/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:27:55 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:27:55 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map)
{
	map->tab = NULL;
	map->collector = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->player_pos[0] = 0;
	map->player_pos[1] = 0;
	map->walls = 0;
	map->exit_pos[0] = 0;
	map->exit_pos[1] = 0;
	map->map_size = 0;
	map->visited = NULL;
	map->steps = 0;
}

void	get_map_size(t_map *map, const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error(map, "ERROR: Cannot open map file. Should be a .ber file!");
	map->size_x = 0;
	map->size_y = 0;
	line = get_next_line(fd);
	if (!line)
		exit_error(map, "ERROR: Empty map file.");
	map->size_x++;
	map->size_y = strlen(line) - 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->size_x++;
		free(line);
	}
	close(fd);
}

int	check_map_file(char **av, t_map *map)
{
	int	fd;
	int	len;

	len = strlen(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_error(map, "ERROR: Cannot open map file!");
	if (len <= 4 || ft_strcmp(&av[1][len - 4], ".ber") != 0)
	{
		ft_printf("ERROR: The file should have a map.ber extension.\n");
		return (EXIT_FAILURE);
	}
	close(fd);
	return (1);
}
