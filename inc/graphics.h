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
# include <stdbool.h>
# include "libft.h"
# define WIDTH 1000
# define HEIGHT 1000

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

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	int			h_window;
	int			w_window;
	int			num;
	t_picture	frame;
}				t_window;

bool			init_graphics(t_window (new)[], int count, char *names[]);
bool			destroy_graphic(t_window *old);
bool			init_picture(t_window *graphics);
bool			destroy_picture(t_window *graphics);
bool			draw_picture(t_window *graphics, int x, int y);
bool			clear_picture(t_window *graphics);

#endif
