/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:55:10 by tbergkul          #+#    #+#             */
/*   Updated: 2019/10/23 17:30:10 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long nbr)
{
	int	x;

	x = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		x++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		x++;
	}
	return (x);
}

char		*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		i;
	int		len;

	nb = n;
	len = ft_len(nb);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		str[i++] = 48;
	while (nb > 0)
	{
		str[--len] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}
