/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:19:29 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/16 15:19:30 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include  <math.h>

void	init_model(t_model *new, t_picture *pic, int width, int height)
{
	new->min = (t_complex){-2.0, -2.0};
	new->max = (t_complex){2.0, new->min.im + (new->max.re - new->min.re)
						* width * height};
	new->factor.re = (new->max.re - new->min.re) / width - 1;
	new->factor.re = (new->max.im - new->min.im) / height - 1;
	new->max_iter = 1;
	new->pic = pic;

}

void set_position(t_model *model, int iterator, int x, int y)
{
	double t;
	int i;

	t = (double)iterator / model->max_iter;
	i = x * model->pic->bits_per_pixel /8 + y * model->pic->size_img_y;

	model->pic->separate_pixels[++i] = (char)(8.5 * pow((1 - t), 3) * t * 255);
	model->pic->separate_pixels[++i] = (char)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	model->pic->separate_pixels[++i] = (char)(9 * (1 - t) * pow(t, 3) * 255);
}

void	update_model(t_model *model)
{
	int x;
	int y;
	int iterator;
	t_complex c;
	t_complex z;

	y = 0;
	while (y < model->pic->heidth)
	{
		c.im = model->max.im - y * model->factor.re;
		x = 0;
		while (x < model->pic->width)
		{
			c.re = model->min.re + x * model->factor.re;
			init_complex(&z, c.re, c.im);
			iterator = 0;
			while(pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iterator < model->max_iter)
			{
				init_complex(&z, pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
						2.0 * z.re * z.im + c.im);
				iterator++;
			}
			set_position(model, iterator, x, y);
			x++;
		}
		y++;
	}
}