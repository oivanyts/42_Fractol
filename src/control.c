/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:57:34 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/16 16:57:36 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int		mouse_hook(int button, int x, int y, void *param)
{
	t_model		*model;
	t_complex	mouse;
	double		scale;

	model = (t_model *)param;
	model->updated = true;
	if (button == SCR_UP || button == SCR_DOWN)
	{
		init_complex(&mouse,
			(double)x / (model->pic->wpic / (model->max.re - model->min.re))
			+ model->min.re,
			(double)y / (model->pic->hpic / (model->max.im - model->min.im))
			* -1 + model->max.im);
		scale = button == SCR_UP ? 0.8 : 1.2;
		button == SCR_UP ? (model->max_iter += 4) : (model->max_iter -= 4);
		interpolation(&model->min, &mouse, scale);
		interpolation(&model->max, &mouse, scale);
	}
	return (0);
}

static int g_curr = 0;

int		exit_on_x(void *last)
{
	t_general	*here;
	int			i;

	i = 0;
	here = last;
	while (i < here->size)
		destroy_graphic(&(*here->view)[i++]);
	exit(EXIT_SUCCESS);
}

int		loop_hook(void *param)
{
	t_general	*gen;
	t_window	*view;
	t_model		*model;

	gen = (t_general *)param;
	view = &(*gen->view)[g_curr];
	model = &(*gen->model)[g_curr];
	if (model->updated)
	{
		handle_threads(model);
		clear_picture(view);
		draw_picture(view, 0, 0);
		model->updated = false;
	}
	if (!model->alive)
	{
		exit_on_x(param);
	}
	return (1);
}

int		expose_hook(void *param)
{
	g_curr = ((t_window *)param)->num;
	return (0);
}
