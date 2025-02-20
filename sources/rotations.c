/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:58:53 by tbesson           #+#    #+#             */
/*   Updated: 2024/03/29 15:59:16 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(-game->player.rot_speed)
		- game->player.dir.y * sin(-game->player.rot_speed);
	game->player.dir.y = old_dir_x * sin(-game->player.rot_speed)
		+ game->player.dir.y * cos(-game->player.rot_speed);
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(-game->player.rot_speed)
		- game->player.plane.y * sin(-game->player.rot_speed);
	game->player.plane.y = old_plane_x * sin(-game->player.rot_speed)
		+ game->player.plane.y * cos(-game->player.rot_speed);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(game->player.rot_speed)
		- game->player.dir.y * sin(game->player.rot_speed);
	game->player.dir.y = old_dir_x * sin(game->player.rot_speed)
		+ game->player.dir.y * cos(game->player.rot_speed);
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(game->player.rot_speed)
		- game->player.plane.y * sin(game->player.rot_speed);
	game->player.plane.y = old_plane_x * sin(game->player.rot_speed)
		+ game->player.plane.y * cos(game->player.rot_speed);
}
