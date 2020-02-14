/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:03:31 by tbergkul          #+#    #+#             */
/*   Updated: 2019/10/28 19:08:01 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *s, char c)
{
	int x;
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
