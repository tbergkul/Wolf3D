/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:40:21 by tbergkul          #+#    #+#             */
/*   Updated: 2019/10/29 15:06:50 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *s, char c)
{
	int	x;
	int	words;

	x = 0;
	while (s[x] == c)
		x++;
	words = 0;
	while (s[x])
	{
		words++;
		while (s[x] && s[x] != c)
			x++;
		while (s[x] == c)
			x++;
	}
	return (words);
}

static int	ft_wl(const char *s, char c)
{
	int	letters;
	int	y;

	letters = 0;
	y = 0;
	while (s[y] == c)
		y++;
	while (s[y] && s[y] != c)
	{
		y++;
		letters++;
	}
	return (letters);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**new;

	if (!s || !(new = (char **)malloc(sizeof(char *) * ft_words(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ft_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			k = 0;
			if (!(new[j] = (char *)malloc(sizeof(char) * ft_wl(s + i, c) + 1)))
				return (NULL);
			while (s[i] && s[i] != c)
				new[j][k++] = s[i++];
			new[j++][k] = '\0';
		}
	}
	new[j] = NULL;
	return (new);
}
