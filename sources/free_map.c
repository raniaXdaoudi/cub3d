/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:35:57 by tamsi             #+#    #+#             */
/*   Updated: 2024/01/26 19:05:51 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_map map)
{
	if (map.no_texture)
		free(map.no_texture);
	if (map.so_texture)
		free(map.so_texture);
	if (map.we_texture)
		free(map.we_texture);
	if (map.ea_texture)
		free(map.ea_texture);
	if (map.f_rgb)
		free(map.f_rgb);
	if (map.c_rgb)
		free(map.c_rgb);
	if (map.full)
		free_tab(map.full);
}
