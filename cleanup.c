/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:00:05 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/08 16:24:11 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (map->tab)
	{
		i = 0;
		while (i < map->size_x)
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
	}
	if (map->visited)
	{
		i = 0;
		while (i < map->size_x)
		{
			free(map->visited[i]);
			i++;
		}
		free(map->visited);
	}
}

int	on_destroy(t_data *data)
{
	cleanup_images(data);
	free_map(data->map);
	mlx_destroy_window(data->ptr, data->win);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	exit(0);
	return (0);
}
