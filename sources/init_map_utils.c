/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:50:50 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/30 02:29:28 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	append_line_to_map_temp(char **map_temp, char *line)
{
	*map_temp = ft_strappend(map_temp, line);
	free(line);
}

void	read_map_lines(int map_fd, char **map_temp)
{
	char	*line;

	*map_temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		append_line_to_map_temp(map_temp, line);
	}
}
