/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:27:15 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:27:15 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw_map(t_data *data)
{
	mlx_clear_window(data->ptr, data->win);
	parse_map(data);
	mlx_put_image_to_window(data->ptr, data->win, data->player_img,
		data->map->player_pos[1] * TILE_SIZE,
		data->map->player_pos[0] * TILE_SIZE);
	mlx_do_sync(data->ptr);
}

int	create_window(t_data *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		exit_error(NULL, "ERROR: MLX INITIALIZATION FAILED!");
	data->win = mlx_new_window(data->ptr, data->map->size_y * TILE_SIZE,
			data->map->size_x * TILE_SIZE, "SO_LONG");
	if (!data->win)
		exit_error(NULL, "ERROR: Could not create window!");
	return (1);
}

void	parse_tile(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->ptr, data->win,
		img, y * TILE_SIZE, x * TILE_SIZE);
}

void	parse_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->size_x)
	{
		j = 0;
		while (j < data->map->size_y)
		{
			if (data->map->tab[i][j] == 0)
				parse_tile(data, data->empty_img, i, j);
			else if (data->map->tab[i][j] == 1)
				parse_tile(data, data->wall_img, i, j);
			else if (data->map->tab[i][j] == 'P')
				parse_tile(data, data->player_img, i, j);
			else if (data->map->tab[i][j] == 'C')
				parse_tile(data, data->collect_img, i, j);
			else if (data->map->tab[i][j] == 'E')
				parse_tile(data, data->exit_img, i, j);
			j++;
		}
		i++;
	}
}

void	cleanup_and_exit(t_data *data)
{
	t_map	*map;
	int		i;

	i = 0;
	map = data->map;
	while (i < map->size_x)
	{
		free(map->tab[i]);
		free(map->visited[i]);
		i++;
	}
	free(map->tab);
	free(map->visited);
	mlx_destroy_image(data->ptr, data->player_img);
	mlx_destroy_image(data->ptr, data->exit_img);
	mlx_destroy_image(data->ptr, data->wall_img);
	mlx_destroy_image(data->ptr, data->empty_img);
	mlx_destroy_image(data->ptr, data->collect_img);
	mlx_destroy_window(data->ptr, data->win);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	exit(EXIT_SUCCESS);
}
