/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamsi <tamsi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:14:16 by tamsi             #+#    #+#             */
/*   Updated: 2023/10/29 15:16:15 by tamsi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	s2 = malloc((n + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = -1;
	while (s1 && ++i < n)
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
