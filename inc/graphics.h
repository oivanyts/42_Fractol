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
#define FRACTOL_GRAPHICS_H

#include "mlx.h"
#include "stdbool.h"

typedef struct	s_pic
{
	void		*img_memory;
	char		*separate_pixels;
	int			width;
	int			heidth;
	int			bits_per_pixel;
	int			size_img_y;
	int			endian;
} 				t_picture;

typedef struct	s_graphics
{
	void		*mlx;
	void		*win;
	t_picture	frame;
	int			height_window;
	int			width_window;
}				t_graphics;

bool			init_graphics(t_graphics *new, char *win_name, int width,int height);
bool			destroy_graphic(t_graphics *new);
bool			init_picture(t_graphics *graphics);
bool			destroy_picture(t_graphics *graphics);
bool			draw_picture(t_graphics *graphics, int x, int y);


#endif
