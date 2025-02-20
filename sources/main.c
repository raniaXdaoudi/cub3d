/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:40:18 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/27 18:16:18 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Usage: ./cub3d map.cub\n", 2), 1);
	game.map_fd = open_map_file(av[1]);
	if (game.map_fd <= 0)
		return (close(game.map_fd), 1);
	init_game(game.map_fd, &game);
	game_loop(&game);
	cleanup(&game);
	return (0);
}
