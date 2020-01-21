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

void	*tread_update(void *model)
{
	t_model		*cur;
	t_complex	c;
	int			x;
	int			y;
	int			it;

	cur = (t_model *)(((t_threads *)model)->model);
	cur->factor.re = (cur->max.re - cur->min.re) / (cur->pic->wpic - 1);
	cur->factor.im = (cur->max.im - cur->min.im) / (cur->pic->hpic - 1);
	y = ((t_threads *)model)->i;
	while (y < cur->pic->hpic)
	{
		c.im = cur->max.im - y * cur->factor.im;
		x = 0;
		while (x < cur->pic->wpic)
		{
			c.re = cur->min.re + x * cur->factor.re;
			cur->fractal(&c, &cur->k, cur->max_iter, &it);
			set_position(((t_threads *)model)->model, it, x, y);
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
