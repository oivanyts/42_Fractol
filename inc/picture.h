/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:32:41 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/15 17:32:44 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PICTURE_H
#define FRACTOL_PICTURE_H


#include "graphics.h"
#include "mlx.h"
#include "stdbool.h"

#define HEIGHT	1500
#define WIDTH	1500

typedef struct	s_pic
{
	void		*img;
	char		*pic_pixels;
	int			bpp;
	int			size_y;
	int			endian;

	bool		(*init)(t_graphics *graphics, t_picture *picture);
	bool		(*destroy)(t_graphics *graphics, t_picture *picture);
} 				t_picture;

bool			init(t_graphics *graphics, t_picture *picture);
bool			destroy(t_graphics *graphics, t_picture *picture);


#endif
