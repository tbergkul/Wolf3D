/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_threed_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:51:15 by tbergkul          #+#    #+#             */
/*   Updated: 2020/01/02 11:48:30 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_threed_array(char ***array)
{
	int	x;
	int	y;

	y = -1;
	while (array[++y])
	{
		x = -1;
		while (array[y][++x])
			ft_putendl(array[y][x]);
	}
}
