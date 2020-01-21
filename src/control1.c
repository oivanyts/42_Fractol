/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:59:53 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/21 13:59:55 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int		julia_mouse(int x, int y, t_model *param)
{
	init_complex(&param->k,
				4 * ((double)x / param->pic->wpic - 0.5),
				4 * ((double)(param->pic->hpic - y) / param->pic->hpic - 0.5));
	param->updated = true;
	return (0);
}

void	init_controls(t_general *general)
{
	int i;

	i = 0;
	while (i < general->size)
	{
		mlx_expose_hook((*general->view)[i].win,
				expose_hook, &(*general->view)[i]);
		mlx_key_hook((*general->view)[i].win,
				key_hook, &((*general->model)[i]));
		mlx_mouse_hook((*general->view)[i].win,
				mouse_hook, &(*general->model)[i]);
		mlx_loop_hook((*general->view)[i].mlx, loop_hook, general);
		mlx_hook((*general->view)[i].win, 17, 1L << 17, exit_on_x, general);
		if ((*general->model)[i].fractal == &julia)
			mlx_hook((*general->view)[i].win, 6, 0,
				julia_mouse, &(*general->model)[i]);
		i++;
	}
}
