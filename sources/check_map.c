/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:12:02 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/30 02:53:40 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	compare_map_char(char c)
{
	char	allowed_map_char[7];
	int		i;

	ft_strcpy(allowed_map_char, "NSEW01 ");
	i = 0;
	while (allowed_map_char[i])
	{
		if (c == allowed_map_char[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_line_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!compare_map_char(line[i]))
			return (ft_putstr_fd("Error\nWrong character in the map.\n", 2), 0);
		i++;
	}
	return (1);
}

int	check_map_full(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!check_line_char(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_map map)
{
	if (!map.no_texture || !map.so_texture
		|| !map.we_texture || !map.ea_texture
		|| !map.f_rgb || !map.c_rgb)
		return (free_map(map), 0);
	if (open(map.no_texture, O_RDONLY) == -1
		|| open(map.so_texture, O_RDONLY) == -1
		|| open(map.we_texture, O_RDONLY) == -1
		|| open(map.ea_texture, O_RDONLY) == -1)
	{
		ft_putstr_fd("Error\nInvalid texture path\n", 2);
		return (free_map(map), 0);
	}
	if (!is_map_closed(map.full)
		|| !check_player_char_map(map.full))
		return (free_map(map), 0);
	return (1);
}
