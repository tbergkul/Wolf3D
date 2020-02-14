/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:43:08 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/14 14:53:12 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
**	Render will check which keys are pressed and act accordingly.
**	Draws the map and displays the image.
*/

void	render(t_w *w)
{
	mlx_hook(w->win, 17, 0, closewin, w);
	mlx_hook(w->win, 2, 0, key_press, w);
	mlx_hook(w->win, 3, 0, key_release, w);
	draw_map(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_loop_hook(w->mlx, moving, w);
	mlx_loop(w->mlx);
}

/*
**	Init_wolf initializes the variables to the "default" value and
**	loads the textures.
*/

void	init_wolf(t_w *w)
{
	w->posx = 3;
	w->posy = 3;
	w->dirx = -1;
	w->diry = 0;
	w->planex = 0;
	w->planey = 0.66;
	w->mspeed = 0.06;
	w->rspeed = 0.06;
	w->forward = 0;
	w->back = 0;
	w->left = 0;
	w->right = 0;
	w->texture = 1;
	texture(w);
}

/*
**	Verify_param checks if the parameter passed to the program
**	is valid or not.
*/

int		verify_param(char *parameter)
{
	if (ft_strcmp(parameter, "maps/map1") == 0)
		return (1);
	else if (ft_strcmp(parameter, "maps/map2") == 0)
		return (1);
	else if (ft_strcmp(parameter, "maps/42") == 0)
		return (1);
	else
		return (0);
	return (1);
}

/*
**	Checks the parameter passed to the program and verifies it. Reads and saves
**	the map, and checks that it's a valid map.
*/

int		main(int ac, char **av)
{
	t_w	*w;
	int fd;

	if (!(w = (t_w *)malloc(sizeof(t_w))))
		return (-1);
	if (ac != 2 || verify_param(av[1]) == 0)
	{
		ft_putendl("\033[36musage: ./wolf maps/mapX\n");
		ft_putendl("\033[33mAvailable maps:\n\033[35m-> map1");
		ft_putendl("\033[32m-> map2\n\033[34m-> 42\n");
		exit(1);
	}
	w->rows = get_height(w, av[1]);
	fd = open(av[1], O_RDONLY);
	if (!(reader(w, &fd)))
		return (0);
	close(fd);
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIN_W, WIN_H, "Wolf3D");
	w->img = mlx_new_image(w->mlx, WIN_W, WIN_H);
	w->img_str = (int*)mlx_get_data_addr(w->img, &w->bpp, &w->sl, &w->endian);
	init_wolf(w);
	render(w);
}
