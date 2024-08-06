/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:28:03 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:28:03 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_and_check_map(char **av, t_map *map, t_data *data)
{
	initialize_map(map);
	check_map_file(av, map);
	get_map_size(map, av[1]);
	check_map_size(map);
	read_map(av[1], map);
	check_map_validation(map);
	data->map = map;
	if (create_window(data) == -1) {
		free_map(map);
		exit_error(map, "ERROR: Failed to create window.");
	}
}


void	load_images(t_data *data, int *img_width, int *img_height)
{
	data->player_img = mlx_xpm_file_to_image(data->ptr,
			"player.xpm", img_width, img_height);
	data->exit_img = mlx_xpm_file_to_image(data->ptr,
			"exit.xpm", img_width, img_height);
	data->wall_img = mlx_xpm_file_to_image(data->ptr,
			"wall.xpm", img_width, img_height);
	data->collect_img = mlx_xpm_file_to_image(data->ptr, "collect.xpm",
			img_width, img_height);
	data->empty_img = mlx_xpm_file_to_image(data->ptr,
			"empty.xpm", img_width, img_height);
	if (data->player_img == NULL || data->exit_img == NULL
		|| data->wall_img == NULL
		|| data->collect_img == NULL || data->empty_img == NULL)
	{
		cleanup_images(data);
		exit(EXIT_FAILURE);
	}
}

void cleanup_images(t_data *data)
{
    if (data->player_img)
        mlx_destroy_image(data->ptr, data->player_img);
    if (data->exit_img)
        mlx_destroy_image(data->ptr, data->exit_img);
    if (data->wall_img)
        mlx_destroy_image(data->ptr, data->wall_img);
    if (data->collect_img)
        mlx_destroy_image(data->ptr, data->collect_img);
    if (data->empty_img)
        mlx_destroy_image(data->ptr, data->empty_img);
}

int main(int ac, char **av)
{
    int img_width;
    int img_height;
    t_map map;
    t_data data;

    if (ac != 2)
        exit_error(NULL, "ERROR INVALID MAP INPUT!!!!!!!!!!!!!!!!!!!!!!!!!");
    initialize_and_check_map(av, &map, &data);
    load_images(&data, &img_width, &img_height);
    redraw_map(&data);
    mlx_hook(data.win, 2, 1L << 0, &handle_keypress, &data);
    mlx_hook(data.win, 17, 0x20000, &on_destroy, &data);
    mlx_loop(data.ptr);
    cleanup_images(&data);
    free_map(&map);
    return (EXIT_SUCCESS);
}

