/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:27:41 by tbesson           #+#    #+#             */
/*   Updated: 2024/03/30 13:12:53 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_color(char **color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_is_number(color[i]))
			return (ft_putstr_fd("Error\nBad color line.\n", 2), 0);
		i++;
	}
	if (i != 3)
		return (ft_putstr_fd("Error\nBad color line.\n", 2), 0);
	return (1);
}

int	check_color_lines(char *str)
{
	char	*tmp;
	char	**color;
	int		ret;

	ret = 0;
	tmp = ft_strndup(str, ft_strlen(str) - 1);
	color = ft_split(tmp, ",");
	ret = parse_color(color);
	free_tab(color);
	free(tmp);
	return (ret);
}
