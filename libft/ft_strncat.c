/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:35:40 by tbergkul          #+#    #+#             */
/*   Updated: 2019/10/18 15:52:36 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	size_t	x;

	i = ft_strlen(s1);
	j = 0;
	x = 0;
	while (s2[j] && x < n)
	{
		s1[i] = s2[j];
		i++;
		j++;
		x++;
	}
	s1[i] = '\0';
	return (s1);
}
