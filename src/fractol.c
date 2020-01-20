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

void	init_model(t_model (*new)[], t_graphics (*pic)[], int size)
{
	int i;
	int width;
	int height;


	i = 0;
	while (i < size)
	{
		width = (*pic)[i].w_window;
		height = (*pic)[i].h_window;
		(*new)[i].min = (t_complex){-2.0, -2.0};
		(*new)[i].max = (t_complex){2.0, (*new)[i].min.im +
				((*new)[i].max.re - (*new)[i].min.re) * width * height};
		(*new)[i].factor.re = ((*new)[i].max.re - (*new)[i].min.re) / width - 1;
		(*new)[i].factor.re = ((*new)[i].max.im - (*new)[i].min.im) / height - 1;
		(*new)[i].max_iter  = 25;
		(*new)[i].pic       = &(*pic)[i].frame;
		i++;
	}

}

void	set_position(t_model *model, int iterator, int x, int y)
{
	double t;
	int i;

	t = (double)iterator / model->max_iter;
	i = x * model->pic->bits_per_pixel /8 + y * model->pic->size_img_y;

	model->pic->pixels[++i] = (char)(8.5 * pow((1 - t), 3) * t * 255);
	model->pic->pixels[++i] = (char)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	model->pic->pixels[++i] = (char)(9 * (1 - t) * pow(t, 3) * 255);
}

void	mandelbrot(double re, double im, int max_iter, int *it)
{
	t_complex z;


	init_complex(&z, re, im);
	it = 0;
	while(pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && *it < max_iter)
	{
		init_complex(&z, pow(z.re, 2.0) - pow(z.im, 2.0) + re,
					 2.0 * z.re * z.im + im);
		it++;
	}
}

void	julia(double re, double im, int max_iter, int *it)
{
	t_complex z;


	init_complex(&z, re, im);
	it = 0;
	while(pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && *it < max_iter)
	{
		init_complex(&z, pow(z.re, 2.0) - pow(z.im, 2.0) + re,
					 2.0 * z.re * z.im + im);
		it++;
	}
}
void	third(double re, double im, int max_iter, int *it)
{
	t_complex z;


	init_complex(&z, re, im);
	it = 0;
	while(pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && *it < max_iter)
	{
		init_complex(&z, pow(z.re, 2.0) - pow(z.im, 2.0) + re,
					 2.0 * z.re * z.im + im);
		it++;
	}
}

void	update_model(t_model *model)
{
	int x;
	int y;
	int iterator;
	t_complex c;
	t_complex z;

	y = 0;
	while (y < model->pic->hpic)
	{
		c.im = model->max.im - y * model->factor.re;
		x = 0;
		while (x < model->pic->wpic)
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