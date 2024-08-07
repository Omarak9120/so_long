/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:59:26 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/07 10:59:26 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->size_x
		|| y < 0 || y >= map->size_y || map->tab[x][y] == 1
		|| map->visited[x][y] == 1)
		return ;
	if (map->tab[x][y] == 'E')
	{
		map->visited[x][y] = 1;
		return ;
	}
	map->visited[x][y] = 1;
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

int	check_valid_path(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	floodfill(map, map->player_pos[0], map->player_pos[1]);
	while (i < map->size_x)
	{
		j = 0;
		while (j < map->size_y)
		{
			if (map->tab[i][j] == 'E' && map->visited[i][j] == 0)
				exit_error(map, "ERROR: EXIT is not reachable!");
			if (map->tab[i][j] == 'C' && map->visited[i][j] == 0)
				exit_error(map, "ERROR: Not all collectors are reachable!");
			j++;
		}
		i++;
	}
	return (1);
}
