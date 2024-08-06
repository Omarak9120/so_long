/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:28:12 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:28:15 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_c(char c)
{
	return (c == '0' || c == '1' || c == 'E' || c == 'C' || c == 'P');
}

int	check_map_size(t_map *map)
{
	if (map->size_x < 3
		|| map->size_y < 3)
		exit_error(map, "ERROR: NOT A VALID MAP SIZE!");
	return (1);
}

int	check_map_collector(t_map *map)
{
	if (map->collector < 1)
		exit_error(map, "ERROR: NEED AT LEAST 1 COLLECTOR!");
	return (1);
}

int	check_map_walls_out(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size_x)
	{
		j = 0;
		while (j < map->size_y)
		{
			if ((i == 0 || j == 0 || i == map->size_x - 1
					|| j == map->size_y - 1)
				&& map->tab[i][j] != 1)
				exit_error(map, "ERROR: SHOULD BE SURROUNDED BY WALLS!");
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_validation(t_map *map)
{
	map->map_size = map->size_x * map->size_y;
	check_map_walls_out(map);
	check_map_size(map);
	check_valid_path(map);
	check_map_collector(map);
	return (1);
}
