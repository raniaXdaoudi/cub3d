/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:59:51 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/29 16:33:21 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_direction(t_player *player, char c)
{
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = 0.66;
	player->plane.y = 0;
	if (c == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (c == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	else if (c == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
}

void	set_player_position(t_player *player, int i, int j)
{
	player->pos.x = (double)j + 0.5;
	player->pos.y = (double)i + 0.5;
}

t_player	init_player(t_map map)
{
	t_player	player;
	int			i;
	int			j;

	i = 0;
	player.move_speed = 0.08;
	player.rot_speed = 0.05;
	while (map.full[i])
	{
		j = 0;
		while (map.full[i][j])
		{
			if (map.full[i][j] == 'N' || map.full[i][j] == 'S'
				|| map.full[i][j] == 'W' || map.full[i][j] == 'E')
			{
				set_player_position(&player, i, j);
				set_player_direction(&player, map.full[i][j]);
				map.full[i][j] = '0';
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}

// t_player	init_player(t_map map)
// {
// 	t_player	player;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	player.move_speed = 0.1;
// 	player.rot_speed = 0.05;
// 	while (map.full[i])
// 	{
// 		j = 0;
// 		while (map.full[i][j])
// 		{
// 			if (map.full[i][j] == 'N' || map.full[i][j] == 'S'
// 				|| map.full[i][j] == 'W' || map.full[i][j] == 'E')
// 			{
// 				player.pos.x = (double)j + 0.5;
// 				player.pos.y = (double)i + 0.5;
// 				if (map.full[i][j] == 'N')
// 				{
// 					player.dir.x = 0;
// 					player.dir.y = -1;
// 					player.plane.x = 0.66;
// 					player.plane.y = 0;
// 				}
// 				else if (map.full[i][j] == 'S')
// 				{
// 					player.dir.x = 0;
// 					player.dir.y = 1;
// 					player.plane.x = -0.66;
// 					player.plane.y = 0;
// 				}
// 				else if (map.full[i][j] == 'W')
// 				{
// 					player.dir.x = -1;
// 					player.dir.y = 0;
// 					player.plane.x = 0;
// 					player.plane.y = -0.66;
// 				}
// 				else if (map.full[i][j] == 'E')
// 				{
// 					player.dir.x = 1;
// 					player.dir.y = 0;
// 					player.plane.x = 0;
// 					player.plane.y = 0.66;
// 				}
// 				map.full[i][j] = '0';
// 				return (player);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (player);
// }
