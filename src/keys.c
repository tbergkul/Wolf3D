/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:27:29 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/17 12:17:47 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
**	Closewin will exit the program when the red X is pressed in the window.
*/

int		closewin(void)
{
	exit(1);
	return (0);
}

/*
**	Key_release checks if a key is released. If a key is released then
**	the corresponding variable will be set to 0. If SHIFT is released then
**	movementspeed will be decreased and rotationspeed increased.
*/

int		key_release(int key, t_w *w)
{
	if (key == KEY_W || key == ARROW_UP)
		w->forward = 0;
	else if (key == KEY_S || key == ARROW_DOWN)
		w->back = 0;
	else if (key == KEY_A || key == ARROW_LEFT)
		w->left = 0;
	else if (key == KEY_D || key == ARROW_RIGHT)
		w->right = 0;
	else if (key == SHIFT)
	{
		w->mspeed = 0.06;
		w->rspeed = 0.06;
	}
	return (0);
}

/*
**	Key_press checks if a key is pressed down. If a key is pressed down then
**	the corresponding variable will be set to 1. If SHIFT is pressed then
**	movementspeed will be increased and rotationspeed decreased.
**	Remove/apply textures by pressing T.
*/

int		key_press(int key, t_w *w)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W || key == ARROW_UP)
		w->forward = 1;
	else if (key == KEY_S || key == ARROW_DOWN)
		w->back = 1;
	else if (key == KEY_A || key == ARROW_LEFT)
		w->left = 1;
	else if (key == KEY_D || key == ARROW_RIGHT)
		w->right = 1;
	else if (key == SHIFT)
	{
		w->mspeed = 0.10;
		w->rspeed = 0.04;
	}
	else if (key == KEY_T)
		w->texture = w->texture == 1 ? 0 : 1;
	return (0);
}

/*
**	Rotating acts only if a A or D are being pressed down. If A/LEFT is
**	pressed down then the player will rotate left etc.
*/

void	rotating(t_w *w)
{
	if (w->left == 1)
	{
		w->diroldx = w->dirx;
		w->dirx = w->dirx * cos(w->rspeed) - w->diry * sin(w->rspeed);
		w->diry = w->diroldx * sin(w->rspeed) +
			w->diry * cos(w->rspeed);
		w->planeoldx = w->planex;
		w->planex = w->planex * cos(w->rspeed) -
			w->planey * sin(w->rspeed);
		w->planey = w->planeoldx * sin(w->rspeed) +
			w->planey * cos(w->rspeed);
	}
	if (w->right == 1)
	{
		w->diroldx = w->dirx;
		w->dirx = w->dirx * cos(-w->rspeed) -
			w->diry * sin(-w->rspeed);
		w->diry = w->diroldx * sin(-w->rspeed) +
			w->diry * cos(-w->rspeed);
		w->planeoldx = w->planex;
		w->planex = w->planex * cos(-w->rspeed) -
			w->planey * sin(-w->rspeed);
		w->planey = w->planeoldx * sin(-w->rspeed) +
			w->planey * cos(-w->rspeed);
	}
}

/*
**	Moving acts only if a W or S are being pressed down. If W/UP is pressed
**	down then the player will move forward etc.
*/

int		moving(t_w *w)
{
	if (w->forward == 1)
	{
		if (w->map[(int)(w->posx + w->dirx * w->mspeed)][(int)(w->posy)] == 0
		|| w->map[(int)(w->posx + w->dirx * w->mspeed)][(int)(w->posy)] == 6)
			w->posx += w->dirx * w->mspeed;
		if (w->map[(int)(w->posx)][(int)(w->posy + w->diry * w->mspeed)] == 0
		|| w->map[(int)(w->posx)][(int)(w->posy + w->diry * w->mspeed)] == 6)
			w->posy += w->diry * w->mspeed;
	}
	if (w->back == 1)
	{
		if (w->map[(int)(w->posx - w->dirx * w->mspeed)][(int)(w->posy)] == 0)
			w->posx -= w->dirx * w->mspeed;
		if (w->map[(int)(w->posx)][(int)(w->posy - w->diry * w->mspeed)] == 0)
			w->posy -= w->diry * w->mspeed;
	}
	rotating(w);
	mlx_destroy_image(w->mlx, w->img);
	w->img = mlx_new_image(w->mlx, WIN_W, WIN_H);
	draw_map(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}
