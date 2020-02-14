/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:08:32 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/14 14:30:04 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	checkmap(t_w *w)
{
	int x;
	int y;

	if (w->rowlen < 4 || w->rowlen >= 150 || w->rows < 4 || w->rows >= 150)
		return (0);
	if (w->map[3][3] != 0)
		return (0);
	y = -1;
	while (++y < w->rows)
	{
		x = -1;
		while (++x < w->rowlen)
		{
			if (w->map[y][x] >= 7 || w->map[y][x] < 0)
				return (0);
			if (y == 0 || y == w->rows - 1)
				if (w->map[y][x] >= 6 || w->map[y][x] <= 0)
					return (0);
			if (x == 0 || x == w->rowlen - 1)
				if (w->map[y][x] >= 6 || w->map[y][x] <= 0)
					return (0);
		}
	}
	return (1);
}

int	fillmap(int *xmap, char *line)
{
	char	**strmap;
	int		x;

	x = 0;
	if (!(xmap))
		return (0);
	strmap = ft_strsplit(line, ' ');
	while (strmap[x])
	{
		xmap[x] = ft_atoi(strmap[x]);
		free(strmap[x]);
		x++;
	}
	free(strmap);
	return (x);
}

int	reader(t_w *w, int *fd)
{
	char	*line;
	int		x;
	int		size;

	w->map = (int**)malloc(sizeof(int*) * (w->rows + 1));
	x = 0;
	size = 0;
	while (get_next_line(*fd, &line))
	{
		w->map[x] = (int*)malloc(sizeof(int) * (w->rowlen + 1));
		size = fillmap(w->map[x], line);
		if (size != w->rowlen)
		{
			free(line);
			return (0);
		}
		free(line);
		x++;
	}
	w->map[x] = NULL;
	if (!(checkmap(w)))
		return (0);
	return (size);
}

int	get_width(char *line)
{
	int		size;
	char	**k;

	k = ft_strsplit(line, ' ');
	size = 0;
	while (k[size])
	{
		free(k[size]);
		size++;
	}
	free(k);
	return (size);
}

int	get_height(t_w *w, char *filename)
{
	int		size;
	int		fd;
	int		comp;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	size = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (size == 0)
			comp = get_width(line);
		if (comp != get_width(line) && size != 0)
			return (0);
		size++;
		free(line);
	}
	w->rowlen = comp;
	close(fd);
	return (size);
}
