/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:22:41 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/17 13:53:03 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
**	Floor is always green, even though textures are applied on
**	walls and sky.
*/

void	draw_floor(t_w *w)
{
	w->y = w->end - 1;
	if (w->x < WIN_W && w->y < WIN_H)
		while (++w->y < WIN_H)
			w->img_str[WIN_W * w->y + w->x] = GREEN;
}

/*
**	Sky will load and save the sky texture into a struct called text.
*/

void	sky(t_w *w)
{
	int i;
	int j;

	i = 768;
	j = 768;
	w->text[6].img = XPM(w->mlx, "textures/endsky.xpm", &i, &j);
	w->text[6].img_str = (int *)(XPMA(w->text[6].img, &w->text[6].bpp,
		&w->text[6].sl, &w->text[6].endian));
}

/*
**	Texture will load and save the textures into a struct called text.
*/

void	texture(t_w *w)
{
	int	i;
	int	j;

	i = 64;
	j = 64;
	w->text[0].img = XPM(w->mlx, "textures/mossy.xpm", &i, &j);
	w->text[0].img_str = (int *)(XPMA(w->text[0].img, &w->text[0].bpp,
		&w->text[0].sl, &w->text[0].endian));
	w->text[1].img = XPM(w->mlx, "textures/diamond.xpm", &i, &j);
	w->text[1].img_str = (int *)(XPMA(w->text[1].img, &w->text[1].bpp,
		&w->text[1].sl, &w->text[1].endian));
	w->text[2].img = XPM(w->mlx, "textures/planks.xpm", &i, &j);
	w->text[2].img_str = (int *)(XPMA(w->text[2].img, &w->text[2].bpp,
		&w->text[2].sl, &w->text[2].endian));
	w->text[3].img = XPM(w->mlx, "textures/bookshelf.xpm", &i, &j);
	w->text[3].img_str = (int *)(XPMA(w->text[3].img, &w->text[3].bpp,
		&w->text[3].sl, &w->text[3].endian));
	w->text[4].img = XPM(w->mlx, "textures/netherrack.xpm", &i, &j);
	w->text[4].img_str = (int *)(XPMA(w->text[4].img, &w->text[4].bpp,
		&w->text[4].sl, &w->text[4].endian));
	w->text[5].img = XPM(w->mlx, "textures/nether.xpm", &i, &j);
	w->text[5].img_str = (int *)(XPMA(w->text[5].img, &w->text[5].bpp,
		&w->text[5].sl, &w->text[5].endian));
	sky(w);
}

/*
**	Wall_texture will draw the wall with the texture. The n variable
**	is calculated to know what kind of wall it is and what kind of
**	texture to use. The wall variable is the exact location where the
**	wall was hit. This is required so that we can calculate which
**	x-coordinate to use in the texture. Textx will be calculated
**	for that. Textx will be constant during this loop, but texty will
**	be the texture y-coordinate that we will recalculate every loop.
*/

void	wall_texture(t_w *w, int temp_start)
{
	w->n = (w->map[(int)w->mapx][(int)w->mapy] - 1) < 0 ? 0 :
		(w->map[(int)w->mapx][(int)w->mapy] - 1);
	if (w->side == 0)
		w->wall = w->lookposy + w->lookdiry * w->walldst;
	else
		w->wall = w->lookposx + w->lookdirx * w->walldst;
	w->textx = (int)(w->wall * (double)(64));
	if (w->side == 1 && w->lookdiry < 0)
		w->textx = 64 - w->textx - 1;
	if (w->side == 0 && w->lookdirx > 0)
		w->textx = 64 - w->textx - 1;
	w->textx = abs(w->textx);
	while (++temp_start <= w->end)
	{
		if (w->x < WIN_W && temp_start < WIN_H)
		{
			w->texty = abs((((temp_start * 256 - WIN_H * 128 +
				w->wallheight * 128) * 64) / w->wallheight) / 256);
			w->img_str[WIN_W * temp_start + w->x] =
				w->text[w->n].img_str[w->texty % 16 * w->text[w->n].sl +
					w->textx % 64 * w->text[w->n].bpp / 8];
		}
	}
}

/*
**	Draw_walls will draw the wall with the texture if w->texture == 1, else draw
**	the walls without textures and only apply a color.
*/

void	draw_walls(t_w *w)
{
	int	temp_start;

	temp_start = w->start - 1;
	if (w->texture == 0)
	{
		if (w->side == 1)
			w->color = ORANGE;
		else
			w->color = RED;
		while (++temp_start <= w->end)
			w->img_str[WIN_W * temp_start + w->x] = w->color;
	}
	else
		wall_texture(w, temp_start);
}
