/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:29:44 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/15 17:29:46 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_GRAPHICS_H
# define FRACTOL_GRAPHICS_H

# include "mlx.h"
# include "stdbool.h"

const char		name[] = {

};
typedef struct	s_pic
{
	void		*img_ptr;
	char		*pixels;
	int			wpic;
	int			hpic;
	int			bits_per_pixel;
	int			size_img_y;
	int			endian;
}				t_picture;

typedef struct	s_graphics
{
	void		*mlx;
	void		*win;
	t_picture	frame;
	int			h_window;
	int			w_window;
}				t_graphics;

bool			init_graphics(t_graphics **new, int count, int width, int height);
bool			destroy_graphic(t_graphics *new);
bool			init_picture(t_graphics *graphics);
bool			destroy_picture(t_graphics *graphics);
bool			draw_picture(t_graphics *graphics, int x, int y);
bool			draw_clocks(t_graphics *graphics, int time);
bool			clear_picture(t_graphics *graphics);

#endif
