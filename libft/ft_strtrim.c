/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:54:59 by tbergkul          #+#    #+#             */
/*   Updated: 2019/10/24 17:33:14 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	end;
	char			*new;

	new = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return ((char *)s);
	end = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	while (i < end && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (i == end)
		return (new);
	if (!(new = (char *)malloc(sizeof(char) * end - i + 2)))
		return (NULL);
	j = 0;
	while (i < end + 1)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
