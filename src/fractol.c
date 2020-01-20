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

void	init_model(t_model (*new)[], t_window (*pic)[], int size)
{
	int i;
	int width;
	int height;

	i = 0;
	while (i < size)
	{
		(*new)[i].alive = true;
		(*new)[i].updated = true;
		width = (*pic)[i].w_window;
		height = (*pic)[i].h_window;
		(*new)[i].k = (t_complex){-0.4, 0.6};
		(*new)[i].min = (t_complex){-2.0, -2.0};
		(*new)[i].max = (t_complex){2.0, (*new)[i].min.im +	(2.0 -
							  (*new)[i].min.re) * width / height};
		(*new)[i].max_iter = 25;
		(*new)[i].pic = &(*pic)[i].frame;
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

void mandelbrot(t_complex *c, t_complex *k, int max_iter, int *it)
{
	t_complex z;

	(void)k;
	z = (t_complex){c->re, c->im};
	*it = 0;
	while(z.re * z.re + z.im * z.im <= 4 && *it < max_iter)
	{
		init_complex(&z, z.re * z.re  - z.im * z.im + c->re,
					 2.0 * z.re * z.im + c->im);
		(*it)++;
	}
}

void	julia(t_complex *c, t_complex *k, int max_iter, int *it)
{
	t_complex z;

	*it = 0;
	z = (t_complex){c->re, c->im};
	while (z.re * z.re + z.im * z.im <= 4 && *it < max_iter)
	{
		init_complex(&z, z.re * z.re - z.im * z.im + k->re,
				2.0 * z.re * z.im + k->im);
		(*it)++;
	}
}
void	third(t_complex *c, t_complex *k, int max_iter, int *it)
{
	t_complex z;

	*it = 0;
	z = (t_complex){c->re, c->im};
	while (z.re * z.re + z.im * z.im <= 4 && *it < max_iter)
	{
		init_complex(&z, z.re * z.re   - z.im * z.im + k->re,
					 2.0 * z.re * z.im + k->im);
		(*it)++;
	}
}

void	update_model(t_model *model)
{
	int x;
	int y;
	int iterator;
	t_complex c;

	y = 0;
	model->factor.re = (model->max.re - model->min.re) /
							(model->pic->wpic - 1);
	model->factor.im = (model->max.im - model->min.im) /
							(model->pic->hpic - 1);
	while (y < model->pic->hpic)
	{
		c.im = model->max.im - y * model->factor.re;
		x = 0;
		while (x < model->pic->wpic)
		{
			c.re = model->min.re + x * model->factor.re;
			model->fractal(&c, &model->k, model->max_iter, &iterator);
			set_position(model, iterator, x, y);
			x++;
		}
		y++;
	}
}