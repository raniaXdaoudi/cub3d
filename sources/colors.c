/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:43:13 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/27 18:06:13 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	color_sky(t_game *game, int x)
{
	char	**skycolor;
	int		color;
	int		y;

	skycolor = ft_split(game->map.c_rgb, ",");
	color = create_trgb(0, ft_atoi(skycolor[0]),
			ft_atoi(skycolor[1]), ft_atoi(skycolor[2]));
	y = 0;
	while (y < game->raycast.draw_start)
	{
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
	free_tab(skycolor);
}

void	color_floor(t_game *game, int x)
{
	char	**floorcolor;
	int		color;
	int		y;

	floorcolor = ft_split(game->map.f_rgb, ",");
	color = create_trgb(0, ft_atoi(floorcolor[0]),
			ft_atoi(floorcolor[1]), ft_atoi(floorcolor[2]));
	y = game->raycast.draw_end;
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
	free_tab(floorcolor);
}
