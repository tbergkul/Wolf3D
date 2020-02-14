/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_twod_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:55:42 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/17 16:57:04 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_twod_array(char **array)
{
	int	y;

	y = -1;
	while (array[++y])
		ft_putendl(array[y]);
}
