/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:06:43 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/29 17:06:14 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == 65307)
	{
		cleanup(game);
		game->window_is_open = 0;
		exit(0);
	}
	game->keys[keysym] = 1;
	return (0);
}

static int	handle_keyrelease(int keysym, t_game *game)
{
	game->keys[keysym] = 0;
	return (0);
}

static int	handle_close(t_game *game)
{
	cleanup(game);
	game->window_is_open = 0;
	exit(0);
}

static int	render_next_frame(t_game *game)
{
	if (game->keys[119] || game->keys[65362])
		move_forward(game);
	if (game->keys[115] || game->keys[65364])
		move_backward(game);
	if (game->keys[97])
		move_right(game);
	if (game->keys[100])
		move_left(game);
	if (game->keys[65361])
		rotate_left(game);
	if (game->keys[65363])
		rotate_right(game);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, handle_keyrelease, game);
	mlx_hook(game->mlx_win, 17, 0, handle_close, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
}
