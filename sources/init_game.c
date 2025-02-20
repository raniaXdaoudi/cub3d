/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:01:36 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/30 02:53:51 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_texture_path(t_game *game, int i)
{
	char	*texture_path;

	if (i == 0)
		texture_path = game->map.no_texture;
	else if (i == 1)
		texture_path = game->map.ea_texture;
	else if (i == 2)
		texture_path = game->map.so_texture;
	else
		texture_path = game->map.we_texture;
	return (texture_path);
}

static void	load_textures(t_game *game)
{
	char	*texture_path;
	int		width;
	int		height;
	int		i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		texture_path = get_texture_path(game, i);
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx,
				texture_path, &width, &height);
		if (!game->textures[i].img)
		{
			ft_putstr_fd("Error\n Couldn't load texture.\n", 2);
			cleanup(game);
			exit(0);
		}
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bits_per_pixel,
				&game->textures[i].line_length, &game->textures[i].endian);
		game->textures[i].width = width;
		game->textures[i].height = height;
		i++;
	}
}

t_data	*get_texture(t_game *game)
{
	t_data	*texture;

	if (game->raycast.side == 0)
	{
		if (game->raycast.ray_dir.x > 0)
			texture = &game->textures[0];
		else
			texture = &game->textures[2];
	}
	else
	{
		if (game->raycast.ray_dir.y > 0)
			texture = &game->textures[1];
		else
			texture = &game->textures[3];
	}
	return (texture);
}

void	init_game(int map_fd, t_game *game)
{
	int	i;

	i = 0;
	game->map = init_map(map_fd);
	if (!check_map(game->map))
		exit(0);
	game->player = init_player(game->map);
	while (i < 65536)
	{
		game->keys[i] = 0;
		i++;
	}
	game->mlx = mlx_init();
	game->img.img = NULL;
	load_textures(game);
	game->mlx_win = mlx_new_window(game->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D");
	game->window_is_open = 1;
}
