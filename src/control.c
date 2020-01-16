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
#include "stdio.h" //


int key_hook(int keycode, void *param)
{
	t_model *tmp = (t_model *)param;
	tmp->updated = true;
	if (keycode == PLUS)
	{
		tmp->max_iter++;
	}
	else if (keycode == MINUS)
	{
		if (tmp->max_iter > 1)
			tmp->max_iter--;
	}
	return printf("keyhook : keykode[%d]\n", keycode);
}

int mouse_hook(int button,int x,int y,void *param)
{
	t_model *tmp = (t_model *)param;
	tmp->updated = true;
	if (button == LMK)
	{
		tmp->max.re /= 1.5;
		tmp->min.re /= 1.5;
	}
	else if (button == RMK)
	{
		tmp->max.re *= 1.5;
		tmp->min.re *= 1.5;
	}
	return printf("mouse_hook : button[%d] at {%d:%d}\n",button, x, y); //
}

int loop_hook(void *param)
{
	t_graphics	*view;
	t_model		*model;

	view = ((struct s_general *)param)->view;
	model = ((struct s_general *)param)->model;
	if (model->updated)
	{
		update_model(model);
		draw_picture(view, 0, 0);
	}
	model->updated = false;
	return (1);
}

void run(t_graphics *view, t_model *model)
{
	struct s_general tmp;

	tmp = (struct s_general) {view, model};
	mlx_key_hook ( view->win, key_hook, model);
	mlx_mouse_hook ( view->win, mouse_hook,  model);
	mlx_loop_hook ( view->mlx, loop_hook, &tmp);
	mlx_loop(view->mlx);
}
