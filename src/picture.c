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

bool init_picture(t_graphics *graphics)
{
	t_picture *image;

	image = &(graphics->frame);
	if (!(image->img_memory = mlx_new_image(graphics->mlx, graphics->width_window,
			graphics->height_window)))
		return (false);
	image->separate_pixels = mlx_get_data_addr(image->img_memory, &(image->bits_per_pixel),
			&(image->size_img_y), &(image->endian));
	image->width = graphics->width_window;
	image->heidth = graphics->height_window;
	return (image->separate_pixels);
}

bool destroy_picture(t_graphics *graphics)
{
	if (graphics)
		return (mlx_destroy_image(graphics->mlx, graphics->frame.img_memory));
	return (false);
}

bool draw_picture(t_graphics *graphics, int x, int y)
{
	if (graphics)
	{
		return (mlx_put_image_to_window(graphics->mlx, graphics->win,
				graphics->frame.img_memory, x, y));
	}
	return (false);
}
