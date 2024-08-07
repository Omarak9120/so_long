/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:00:11 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/07 11:00:12 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_tab(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->tab)
	{
		while (i < map->size_x)
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
		map->tab = NULL;
	}
}

static void	clear_visited(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->visited)
	{
		while (i < map->size_x)
		{
			free(map->visited[i]);
			i++;
		}
		free(map->visited);
		map->visited = NULL;
	}
}

void	exit_error(t_map *map, char *msg)
{
	clear_tab(map);
	clear_visited(map);
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	fstrlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
