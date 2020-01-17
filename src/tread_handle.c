/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:11:00 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/17 18:11:04 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tread_handle.h"
#include "fractol.h"

void	*tread_update(void *model)
{
	t_threads	*cur;
	t_complex	c;
	int			x;
	int			y;
	int			it;

	cur = (t_threads *)model;
	cur->model->factor.re = (cur->model->max.re - cur->model->min.re) /
			(cur->model->pic->wpic - 1);
	cur->model->factor.im = (cur->model->max.im - cur->model->min.im) /
			(cur->model->pic->hpic - 1);
	y = cur->i;
	while (y < cur->model->pic->hpic)
	{
		c.im = cur->model->max.im - y * cur->model->factor.im;
		x = 0;
		while (x < cur->model->pic->wpic)
		{
			c.re = cur->model->min.re + x * cur->model->factor.re;
			mandelbrot(c.re, c.im, cur->model->max_iter, &it);
			set_position(cur->model, it, x, y);
			x++;
		}
		y += MAX_THREADS;
	}
	return (0);
}

void	add_tread(t_model *model, t_threads *fresh)
{
	static int i;

	fresh->model = model;
	fresh->i = i++ % MAX_THREADS;
	pthread_create(&fresh->worker, 0, tread_update, (void *)fresh);
}

bool	join_thread(t_threads *old)
{
	return (pthread_join(old->worker, NULL));
}

void	handle_threads(t_model *model)
{
	t_threads	tread_array[MAX_THREADS];
	int			i;

	i = 0;
	while (i < MAX_THREADS)
	{
		add_tread(model, &tread_array[i++]);
	}
	while (i--)
	{
		join_thread(&tread_array[i]);
	}
}
