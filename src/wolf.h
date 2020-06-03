/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:45:21 by tbergkul          #+#    #+#             */
/*   Updated: 2020/02/17 12:41:54 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>

/*
**	Screen resolution.
*/

# define WIN_W 1024
# define WIN_H 768

/*
**	Colors.
*/

# define RED 16711680
# define ORANGE 16742400
# define BLUE 255
# define GREEN 0x006400

/*
**	Shortenings for some functions.
*/

# define XPM mlx_xpm_file_to_image
# define XPMA mlx_get_data_addr

/*
**	Keys to operate the program.
*/

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_T 17
# define SHIFT 257
# define KEY_ESC 53

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

/*
**	Struct where the textures will be saved.
*/

typedef struct	s_text
{
	void		*img;
	int			*img_str;
	int			endian;
	int			sl;
	int			bpp;
}				t_text;

/*
**	Struct with all variables.
*/

typedef struct	s_w
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_str;
	int			endian;
	int			sl;
	int			bpp;
	int			**map;
	int			rows;
	int			rowlen;
	int			x;
	int			y;
	double		posx;
	double		posy;
	double		camera;
	double		lookposx;
	double		lookposy;
	double		lookdirx;
	double		lookdiry;
	double		dirx;
	double		diry;
	double		diroldx;
	double		planex;
	double		planey;
	double		planeoldx;
	int			mapx;
	int			mapy;
	int			wallhit;
	double		walldst;
	int			stepx;
	int			stepy;
	int			start;
	int			end;
	int			wallheight;
	int			color;
	int			side;
	double		sidedisx;
	double		sidedisy;
	double		mspeed;
	double		rspeed;
	double		nextx;
	double		nexty;
	int			forward;
	int			back;
	int			right;
	int			left;
	int			textx;
	int			texty;
	double		wall;
	int			n;
	int			texture;
	t_text		text[7];
}				t_w;

void			texture(t_w *w);
void			draw_floor(t_w *w);
void			draw_walls(t_w *w);
void			draw_map(t_w *w);
int				closewin(void);
int				key_release(int key, t_w *w);
int				key_press(int key, t_w *w);
int				moving(t_w *w);
int				get_height(t_w *w, char *filename);
int				reader(t_w *w, int *fd);

#endif
