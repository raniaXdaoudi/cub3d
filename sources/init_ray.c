/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:19:39 by tamsi             #+#    #+#             */
/*   Updated: 2024/03/27 14:19:43 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_raycast *raycast)
{
	raycast->hit = 0;
	raycast->side = 0;
	raycast->perp_wall_dist = 0;
	raycast->draw_start = 0;
	raycast->draw_end = 0;
	raycast->line_height = 0;
	raycast->camera_x = 0;
	raycast->ray_dir.x = 0;
	raycast->ray_dir.y = 0;
	raycast->map_pos.x = 0;
	raycast->map_pos.y = 0;
	raycast->delta_dist.x = 0;
	raycast->delta_dist.y = 0;
	raycast->step.x = 0;
	raycast->step.y = 0;
	raycast->side_dist.x = 0;
	raycast->side_dist.y = 0;
}
