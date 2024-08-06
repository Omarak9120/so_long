/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:28:26 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:28:28 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_helper_extra(t_map *map, char *c, int *i, int *j)
{
	if (*c == '1')
		map->tab[*i][*j] = 1;
	else if (*c == '0')
		map->tab[*i][*j] = 0;
	else if (*c == 'C')
	{
		map->tab[*i][*j] = 'C';
		map->collector++;
	}
}

void	read_helper(t_map *map, char *c, int *i, int *j)
{
	if (!(is_valid_c(*c)))
		map->error = 1;
	else if (*c == 'P')
	{
		map->tab[*i][*j] = 'P';
		map->player_pos[0] = *i;
		map->player_pos[1] = *j;
		map->player_count++;
	}
	else if (*c == 'E')
	{
		map->tab[*i][*j] = 'E';
		map->exit_pos[0] = *i;
		map->exit_pos[1] = *j;
		map->exit_count++;
	}
	else
		read_helper_extra(map, c, i, j);
}

void	handle_error(t_map *map, int fd, int i)
{
	if (i != map->size_x)
		exit_error(map, "ERROR: Incorrect number of lines in map file.");
	if (map->exit_count != 1 || map->player_count != 1)
		map->error = 1;
	close(fd);
	if (map->error == 1)
		exit_error(map, "ERROR!");
}

void	loop_read(t_map *map, char *line, int i, int j)
{
	int		len;
	char	c;

	len = fstrlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (fstrlen(line) != map->size_y)
	{
		map->error = 1;
		return ;
	}
	while (j < map->size_y)
	{
		c = line[j];
		read_helper(map, &c, &i, &j);
		j++;
	}
}
