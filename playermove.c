/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:59:54 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/07 10:59:54 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keypress(int keycode, t_data *data, int *new_x, int *new_y)
{
	data->flag = 0;
	if (keycode == KEY_A)
		(*new_y)--;
	else if (keycode == KEY_D)
		(*new_y)++;
	else if (keycode == KEY_S)
		(*new_x)++;
	else if (keycode == KEY_W)
		(*new_x)--;
	else if (keycode == KEY_ESC)
		cleanup_and_exit(data);
	else
		data->flag = 1;
}

static void	printf_win(t_data *data)
{
	ft_printf("YOU WIN!\n");
	cleanup_and_exit(data);
}

static void	printf_steps_and_draw_map(t_data *data)
{
	if (data->flag == 0)
	{
		data->map->steps++;
		ft_printf("Steps: %d\n", data->map->steps);
	}
	redraw_map(data);
}

static void	collected_collectables(t_data *data, int new_x, int new_y)
{
	if (data->map->tab[new_x][new_y] == 'C')
	{
		data->map->collector--;
	}
	data->map->tab[new_x][new_y] = 'P';
	printf_steps_and_draw_map(data);
}

int	handle_keypress(int keycode, t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->map->player_pos[0];
	new_y = data->map->player_pos[1];
	keypress(keycode, data, &new_x, &new_y);
	if (data->map->tab[new_x][new_y] == 'E' && data->map->collector == 0)
		printf_win(data);
	else if (data->map->tab[new_x][new_y] == 'E' && data->map->collector != 0)
	{
		new_x = data->map->player_pos[0];
		new_y = data->map->player_pos[1];
		return (0);
	}
	if (new_x >= 0 && new_x < data->map->size_x
		&& new_y >= 0 && new_y < data->map->size_y
		&& data->map->tab[new_x][new_y] != 1)
	{
		data->map->tab[data->map->player_pos[0]][data->map->player_pos[1]] = 0;
		data->map->player_pos[0] = new_x;
		data->map->player_pos[1] = new_y;
		collected_collectables(data, new_x, new_y);
	}
	return (0);
}
