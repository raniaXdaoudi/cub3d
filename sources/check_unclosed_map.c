/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unclosed_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:39:22 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/30 02:53:49 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

static char	**copy_map(char **map)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = malloc((ft_tablen(map) + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'N' || map_copy[i][j] == 'S'
				|| map_copy[i][j] == 'E' || map_copy[i][j] == 'W')
				map_copy[i][j] = '0';
			j++;
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static int	check_surroundings(char **map, int y, int x)
{
	int	dirs[4][2];
	int	dy;
	int	dx;
	int	i;

	dirs[0][0] = -1;
	dirs[0][1] = 0;
	dirs[1][0] = 1;
	dirs[1][1] = 0;
	dirs[2][0] = 0;
	dirs[2][1] = -1;
	dirs[3][0] = 0;
	dirs[3][1] = 1;
	i = 0;
	while (i < 4)
	{
		dy = y + dirs[i][0];
		dx = x + dirs[i][1];
		if (map[dy] == NULL || map[dy][dx] == '\0'
			|| map[dy][dx] == ' ' || (map[dy][dx] != '1' && map[dy][dx] != '0'))
			return (0);
		i++;
	}
	return (1);
}

int	is_map_closed(char **map)
{
	int		y;
	int		x;
	char	**map_copy;

	y = -1;
	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	while (map_copy[++y])
	{
		x = 0;
		while (map_copy[y][x] != '\0')
		{
			if (map_copy[y][x] == '0' && !check_surroundings(map_copy, y, x))
			{
				free_tab(map_copy);
				ft_putstr_fd("Error\nThe Map is unclosed.\n", 2);
				return (0);
			}
			x++;
		}
	}
	free_tab(map_copy);
	return (1);
}
