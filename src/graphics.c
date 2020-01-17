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

bool	init_graphics(t_graphics **new, int count, int width, int height)
{
	int i;

	i = 0;
	while (i <= count)
	{
		if (!(new[i]->mlx = mlx_init()))
		{
			return (false);
		}
		if (!(new[i]->win = mlx_new_window(new[i]->mlx, width, height,)))
		{
			return (false);
		}
		init_picture(new[i]);

	}


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
