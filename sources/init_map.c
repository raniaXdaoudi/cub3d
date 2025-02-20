/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:15:27 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/30 13:11:38 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_setup_char(char *line)
{
	if (ft_strncmp(line, NO_CHAR, 3) != 0 && ft_strncmp(line, SO_CHAR, 3) != 0
		&& ft_strncmp(line, WE_CHAR, 3) != 0
		&& ft_strncmp(line, EA_CHAR, 3) != 0
		&& ft_strncmp(line, F_CHAR, 2) != 0 && ft_strncmp(line, C_CHAR, 2) != 0)
	{
		ft_putstr_fd("Error\nBad setup lines.\n", 2);
		return (0);
	}
	return (1);
}

static t_map	init_setup(char *line, t_map map)
{
	char	**setup;

	setup = ft_split(line, " ");
	if (ft_strcmp(setup[0], "NO") == 0)
		map.no_texture = ft_strndup(setup[1], ft_strlen(setup[1]) - 1);
	else if (ft_strcmp(setup[0], "SO") == 0)
		map.so_texture = ft_strndup(setup[1], ft_strlen(setup[1]) - 1);
	else if (ft_strcmp(setup[0], "WE") == 0)
		map.we_texture = ft_strndup(setup[1], ft_strlen(setup[1]) - 1);
	else if (ft_strcmp(setup[0], "EA") == 0)
		map.ea_texture = ft_strndup(setup[1], ft_strlen(setup[1]) - 1);
	else if (ft_strcmp(setup[0], "F") == 0 && check_color_lines(setup[1]))
		map.f_rgb = ft_strndup(setup[1], ft_strlen(setup[1]) - 1);
	else if (ft_strcmp(setup[0], "C") == 0 && check_color_lines(setup[1]))
		map.c_rgb = ft_strndup(setup[1], ft_strlen(setup[1]) - 1);
	free_tab(setup);
	return (map);
}

static t_map	set_map_null(void)
{
	t_map	map;

	map.no_texture = NULL;
	map.so_texture = NULL;
	map.we_texture = NULL;
	map.ea_texture = NULL;
	map.f_rgb = NULL;
	map.c_rgb = NULL;
	map.full = NULL;
	return (map);
}

static t_map	init_map_setup(int map_fd, t_map map)
{
	char	*line;

	line = get_next_line(map_fd);
	if (!line)
		return (ft_putstr_fd("Error\nThe Map is empty.\n", 2), map);
	while (line && ft_strlen(line) > 1 && check_setup_char(line))
	{
		map = init_setup(line, map);
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
	return (map);
}

t_map	init_map(int map_fd)
{
	t_map	map;
	char	*map_temp;

	map = set_map_null();
	map = init_map_setup(map_fd, map);
	read_map_lines(map_fd, &map_temp);
	close(map_fd);
	map.full = ft_split(map_temp, "\n");
	free(map_temp);
	return (map);
}
