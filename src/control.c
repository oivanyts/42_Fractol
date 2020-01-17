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
#include "stdio.h"
#include "tread_handle.h"
#include <time.h>

int		key_hook(int keycode, void *param)
{
	t_model *model;

	model = (t_model *)param;
	model->updated = true;
	if (keycode == PLUS)
	{
		model->max_iter++;
	}
	else if (keycode == MINUS && model->max_iter > 1)
	{
		model->max_iter--;
	}
	return (0);
}

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

int		loop_hook(void *param)
{
	t_graphics	*view;
	t_model		*model;
	clock_t		start;

	view = ((struct s_general *)param)->view;
	model = ((struct s_general *)param)->model;
	if (model->updated)
	{
		start = clock();
		handle_threads(model);
		clear_picture(view);
		draw_picture(view, 0, 0);
		draw_clocks(view, (clock() - start) / 1000);
	}
	model->updated = false;
	return (1);
}

void	run(t_graphics *view, t_model *model)
{
	struct s_general tmp;

	tmp = (struct s_general) {view, model};
	mlx_key_hook(view->win, key_hook, model);
	mlx_mouse_hook(view->win, mouse_hook, model);
	mlx_loop_hook(view->mlx, loop_hook, &tmp);
	mlx_loop(view->mlx);
}
