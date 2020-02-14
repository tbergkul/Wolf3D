/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:55:11 by tbergkul          #+#    #+#             */
/*   Updated: 2019/10/25 12:19:22 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	char		*src2;
	size_t		i;

	if (src == dst)
		return (dst);
	i = -1;
	dst2 = (char *)dst;
	src2 = (char *)src;
	if (len == 0)
		return (dst);
	if (src2 < dst2)
		while (0 < len--)
			dst2[len] = src2[len];
	else
		while (++i < len)
			dst2[i] = src2[i];
	return (dst);
}
