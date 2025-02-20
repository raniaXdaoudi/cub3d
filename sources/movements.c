/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:37:45 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/29 15:59:13 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = (game->player.pos.x + game->player.dir.x * game->player.move_speed);
	new_y = (game->player.pos.y + game->player.dir.y * game->player.move_speed);
	if (new_x >= 0 && new_x < SCREEN_WIDTH
		&& game->map.full[(int)new_y][(int)new_x] == '0')
		game->player.pos.x += game->player.dir.x * game->player.move_speed;
	if (new_y >= 0 && new_y < SCREEN_HEIGHT
		&& game->map.full[(int)new_y][(int)new_x] == '0')
		game->player.pos.y += game->player.dir.y * game->player.move_speed;
}

void	move_backward(t_game *game)
{
	double	newx;
	double	newy;

	newx = (game->player.pos.x - game->player.dir.x * game->player.move_speed);
	newy = (game->player.pos.y - game->player.dir.y * game->player.move_speed);
	if (newx >= 0 && newx < SCREEN_WIDTH
		&& game->map.full[(int)newy][(int)newx] == '0')
		game->player.pos.x -= game->player.dir.x * game->player.move_speed;
	if (newy >= 0 && newy < SCREEN_HEIGHT
		&& game->map.full[(int)newy][(int)newx] == '0')
		game->player.pos.y -= game->player.dir.y * game->player.move_speed;
}

void	move_left(t_game *game)
{
	double	newx;
	double	newy;

	newx = (game->player.pos.x - game->player.dir.y * game->player.move_speed);
	newy = (game->player.pos.y + game->player.dir.x * game->player.move_speed);
	if (newx >= 0 && newx < SCREEN_WIDTH
		&& game->map.full[(int)newy][(int)newx] == '0')
		game->player.pos.x -= game->player.dir.y * game->player.move_speed;
	if (newy >= 0 && newy < SCREEN_HEIGHT
		&& game->map.full[(int)newy][(int)newx] == '0')
		game->player.pos.y += game->player.dir.x * game->player.move_speed;
}

void	move_right(t_game *game)
{
	double	newx;
	double	newy;

	newx = (game->player.pos.x + game->player.dir.y * game->player.move_speed);
	newy = (game->player.pos.y - game->player.dir.x * game->player.move_speed);
	if (newx >= 0 && newx < SCREEN_WIDTH
		&& game->map.full[(int)newy][(int)newx] == '0')
		game->player.pos.x += game->player.dir.y * game->player.move_speed;
	if (newy >= 0 && newy < SCREEN_HEIGHT
		&& game->map.full[(int)newy][(int)newx] == '0')
		game->player.pos.y -= game->player.dir.x * game->player.move_speed;
}
