/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:05:00 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/29 17:32:17 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_info(t_game *game, int x)
{
	game->raycast.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	game->raycast.ray_dir.x = game->player.dir.x
		+ game->player.plane.x * game->raycast.camera_x;
	game->raycast.ray_dir.y = game->player.dir.y
		+ game->player.plane.y * game->raycast.camera_x;
	game->raycast.map_pos.x = (int)game->player.pos.x;
	game->raycast.map_pos.y = (int)game->player.pos.y;
	game->raycast.delta_dist.x = fabs(1 / game->raycast.ray_dir.x);
	game->raycast.delta_dist.y = fabs(1 / game->raycast.ray_dir.y);
	game->raycast.hit = 0;
}

static void	calculate_step_and_side_dist(t_game *game)
{
	if (game->raycast.ray_dir.x < 0)
	{
		game->raycast.step.x = -1;
		game->raycast.side_dist.x = (game->player.pos.x
				- game->raycast.map_pos.x) * game->raycast.delta_dist.x;
	}
	else
	{
		game->raycast.step.x = 1;
		game->raycast.side_dist.x = (game->raycast.map_pos.x
				+ 1.0 - game->player.pos.x) * game->raycast.delta_dist.x;
	}
	if (game->raycast.ray_dir.y < 0)
	{
		game->raycast.step.y = -1;
		game->raycast.side_dist.y = (game->player.pos.y
				- game->raycast.map_pos.y) * game->raycast.delta_dist.y;
	}
	else
	{
		game->raycast.step.y = 1;
		game->raycast.side_dist.y = (game->raycast.map_pos.y
				+ 1.0 - game->player.pos.y) * game->raycast.delta_dist.y;
	}
}

static void	perform_dda(t_game *game)
{
	while (!game->raycast.hit)
	{
		if (game->raycast.side_dist.x < game->raycast.side_dist.y)
		{
			game->raycast.side_dist.x += game->raycast.delta_dist.x;
			game->raycast.map_pos.x += game->raycast.step.x;
			game->raycast.side = 0;
		}
		else
		{
			game->raycast.side_dist.y += game->raycast.delta_dist.y;
			game->raycast.map_pos.y += game->raycast.step.y;
			game->raycast.side = 1;
		}
		if (game->map.full[game->raycast.map_pos.y][game->raycast.map_pos.x]
			== '1')
			game->raycast.hit = 1;
	}
}

static void	calculate_distance_projection(t_game *game)
{
	if (game->raycast.side == 0)
		game->raycast.perp_wall_dist = game->raycast.side_dist.x
			- game->raycast.delta_dist.x;
	else
		game->raycast.perp_wall_dist = game->raycast.side_dist.y
			- game->raycast.delta_dist.y;
	game->raycast.line_height = (int)(SCREEN_HEIGHT
			/ game->raycast.perp_wall_dist);
	game->raycast.draw_start = -(game->raycast.line_height)
		/ 2 + SCREEN_HEIGHT / 2;
	if (game->raycast.draw_start < 0)
		game->raycast.draw_start = 0;
	game->raycast.draw_end = game->raycast.line_height
		/ 2 + SCREEN_HEIGHT / 2;
	if (game->raycast.draw_end >= SCREEN_HEIGHT)
		game->raycast.draw_end = SCREEN_HEIGHT - 1;
}

void	raycasting(t_game *game)
{
	int		x;
	t_data	*texture;

	init_ray(&game->raycast);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray_info(game, x);
		calculate_step_and_side_dist(game);
		perform_dda(game);
		calculate_distance_projection(game);
		texture = get_texture(game);
		color_sky(game, x);
		draw_texture_column(game, texture, x);
		color_floor(game, x);
		x++;
	}
}
