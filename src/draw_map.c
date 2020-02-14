/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:52:41 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/14 16:12:52 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
**
*/

void	line_draw_init(t_w *w)
{
	w->deldistx = sqrt(1 + (w->lookdiry * w->lookdiry) /
		(w->lookdirx * w->lookdirx));
	w->deldisty = sqrt(1 + (w->lookdirx * w->lookdirx) /
		(w->lookdiry * w->lookdiry));
	if (w->lookdirx < 0)
	{
		w->stepx = -1;
		w->sidedisx = (w->lookposx - w->mapx) * w->deldistx;
	}
	else
	{
		w->stepx = 1;
		w->sidedisx = (w->mapx + 1.0 - w->lookposx) * w->deldistx;
	}
	if (w->lookdiry < 0)
	{
		w->stepy = -1;
		w->sidedisy = (w->lookposy - w->mapy) * w->deldisty;
	}
	else
	{
		w->stepy = 1;
		w->sidedisy = (w->mapy + 1.0 - w->lookposy) * w->deldisty;
	}
}

/*
**
*/

void	line_draw(t_w *w)
{
	w->wallhit = 0;
	while (w->wallhit == 0)
	{
		if (w->sidedisx < w->sidedisy)
		{
			w->sidedisx += w->deldistx;
			w->mapx += w->stepx;
			w->side = 0;
		}
		else
		{
			w->sidedisy += w->deldisty;
			w->mapy += w->stepy;
			w->side = 1;
		}
		if (w->map[w->mapx][w->mapy] > 0)
			w->wallhit = 1;
	}
}

/*
**
*/

void	draw_init(t_w *w)
{
	w->camera = 2 * w->x / (double)WIN_W - 1;
	w->lookposx = w->posx;
	w->lookposy = w->posy;
	w->lookdirx = w->dirx + w->planex * w->camera;
	w->lookdiry = w->diry + w->planey * w->camera;
	w->mapx = (int)w->lookposx;
	w->mapy = (int)w->lookposy;
	line_draw_init(w);
	line_draw(w);
	if (w->side == 0)
		w->walldst = (w->mapx - w->lookposx + (1 - w->stepx) / 2) / w->lookdirx;
	else
		w->walldst = (w->mapy - w->lookposy + (1 - w->stepy) / 2) / w->lookdiry;
}

/*
**	This function will first draw the sky, then draw the floor.
**	Sky is blue if no textures are being applied.
*/

void	draw_sky_floor(t_w *w)
{
	if (w->start > 0)
	{
		if (w->texture == 0)
		{
			w->y = -1;
			if (w->x < WIN_W && w->y < WIN_H)
				while (++w->y < w->start)
					w->img_str[WIN_W * w->y + w->x] = BLUE;
		}
		else
		{
			w->y = -1;
			if (w->x < WIN_W && w->y < WIN_H)
				while (++w->y < w->start)
					w->img_str[WIN_W * w->y + w->x] =
						w->text[6].img_str[w->y % 180 * w->text[6].sl +
							w->x % 180 * w->text[6].bpp / 8];
		}
	}
	if (w->end > 0)
		draw_floor(w);
}

/*
**	Draw_map will draw the map starting from the left side going through
**	one line at a time. There will be a wall on every x-coordinate of
**	the screen (in the players field of view). The thing is to calculate
**	the height of the wall at that particualar x-coordinate of the screen.
**	Then draws that part of the wall, sky and floor.
*/

void	draw_map(t_w *w)
{
	w->x = -1;
	while (++w->x < WIN_W)
	{
		draw_init(w);
		w->wallheight = (int)(WIN_H / w->walldst);
		w->start = -w->wallheight / 2 + WIN_H / 2;
		if (w->start < 0)
			w->start = 0;
		w->end = w->wallheight / 2 + WIN_H / 2;
		if (w->end >= WIN_H)
			w->end = WIN_H - 1;
		draw_walls(w);
		draw_sky_floor(w);
	}
}
