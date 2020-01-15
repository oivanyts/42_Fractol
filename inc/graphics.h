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

#include "picture.h"
#include "mlx.h"
#include "stdbool.h"

#define HEIGHT	1500
#define WIDTH	1500

typedef struct	s_graphics
{
	void		*mlx;
	void		*win;

}				t_graphics;

bool			initLib();
bool			initWindow();




#endif
