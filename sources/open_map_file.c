/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:27:26 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/30 02:55:43 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_extension(char *map_path)
{
	if (!ft_strstr(map_path, ".cub"))
		return (0);
	return (1);
}

int	open_map_file(char *map_path)
{
	int	map_fd;

	if (!check_map_extension(map_path))
		return (
			ft_putstr_fd("Error\nBad Map extension, it must be .cub.\n", 2),
			0
		);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (ft_putstr_fd("Error\nThe Map couldn't be opened.\n", 2), 0);
	return (map_fd);
}
