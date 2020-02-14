/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:59 by tbergkul          #+#    #+#             */
/*   Updated: 2019/10/23 19:17:56 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str2;

	str2 = (char *)str;
	i = 0;
	if (find[i] == '\0')
		return (str2);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == find[j] && i + j < len)
		{
			j++;
			if (find[j] == '\0')
				return (&str2[i]);
		}
		i++;
	}
	return (NULL);
}
