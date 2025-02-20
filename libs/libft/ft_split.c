/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesson <tbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:58:26 by tbesson           #+#    #+#             */
/*   Updated: 2023/07/04 14:26:49 by tbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_word_len(char const *str, char *c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i] && is_charset(c, str[i]))
		i++;
	while (str[i] && !is_charset(c, str[i]))
	{
		i++;
		len++;
	}
	return (len);
}

static int	count_words(char const *str, char *c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		while (is_charset(c, str[i]) && str[i])
			i++;
		if (!is_charset(c, str[i]) && str[i])
		{
			count++;
			while (!is_charset(c, str[i]) && str[i])
				i++;
		}
	}
	return (count);
}

static char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char *c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (i < count_words(s, c))
	{
		j = 0;
		tab[i] = malloc((ft_word_len(&s[k], c) + 1) * sizeof(char));
		if (!tab[i])
			return (ft_free_tab(tab));
		while (is_charset(c, s[k]) && s[k])
			k++;
		while (!is_charset(c, s[k]) && s[k])
			tab[i][j++] = s[k++];
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
