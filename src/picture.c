/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:31:53 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/15 17:31:57 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_picture(t_graphics *graphics)
{
	t_picture *image;

	image = &(graphics->frame);
	if (!(image->img_ptr= mlx_new_image(graphics->mlx, graphics->w_window,
			graphics->h_window)))
		return (false);
	image->pixels = mlx_get_data_addr(image->img_ptr, &(image->bits_per_pixel),
			&(image->size_img_y), &(image->endian));
	image->wpic = graphics->w_window;
	image->hpic = graphics->h_window;
	return (image->pixels);
}

bool	destroy_picture(t_graphics *graphics)
{
	if (graphics)
		return (mlx_destroy_image(graphics->mlx, graphics->frame.img_ptr));
	return (false);
}

bool	draw_picture(t_graphics *graphics, int x, int y)
{
	if (graphics)
	{
		return (mlx_put_image_to_window(graphics->mlx, graphics->win,
				graphics->frame.img_ptr, x, y));
	}
	return (false);
}

bool	draw_clocks(t_graphics *graphics, int time)
{
	if (graphics)
	{
		return (mlx_string_put(graphics->mlx, graphics->win, 2,2, 0xff,
				ft_itoa(time)));
	}
	return (false);
}

bool	clear_picture(t_graphics *graphics)
{
	if (graphics)
	{
		return (mlx_clear_window(graphics->mlx, graphics->win));
	}
	return (false);
}