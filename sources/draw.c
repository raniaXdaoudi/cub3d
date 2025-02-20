/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:02:35 by tamsi             #+#    #+#             */
/*   Updated: 2024/02/18 23:03:07 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	calculate_wall_x(t_game *game)
{
	double	wall_x;

	if (game->raycast.side == 0)
		wall_x = game->player.pos.y + game->raycast.perp_wall_dist
			* game->raycast.ray_dir.y;
	else
		wall_x = game->player.pos.x + game->raycast.perp_wall_dist
			* game->raycast.ray_dir.x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

void	draw_texture_column(t_game *game, t_data *texture, int x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;

	y = game->raycast.draw_start;
	step = 1.0 * texture->height / game->raycast.line_height;
	tex_pos = (game->raycast.draw_start - SCREEN_HEIGHT / 2
			+ game->raycast.line_height / 2) * step;
	while (y < game->raycast.draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		my_mlx_pixel_put(&game->img, x, y,
			((int *)texture->addr)[texture->height * tex_y
			+ (int)(calculate_wall_x(game) * (double)texture->width)]);
		y++;
	}
}
