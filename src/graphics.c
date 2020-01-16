/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:29:15 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/15 17:29:17 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_graphics(t_graphics *new, char *win_name, int width, int height)
{
	if (!(new->mlx = mlx_init()))
	{
		return (false);
	}
	new->height_window = height;
	new->width_window = width;
	if (!(new->win = mlx_new_window(new->mlx, width, height, win_name)))
	{
		return (false);
	}

	init_picture(new);
	return (true);
}

bool	destroy_graphic(t_graphics *old)
{
	if (!old || !destroy_picture(old))
	{
		return (false);
	}
	if (old->win)
	{
		return (mlx_destroy_window(old->mlx, old->win));
	}
	return (false);
}
