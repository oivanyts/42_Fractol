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

#include "picture.h"

bool init(t_graphics *graphics, t_picture *picture)
{
	return (picture = mlx_new_image(graphics->mlx, WIDTH, HEIGHT));
}

bool destroy(t_graphics *graphics, t_picture *picture)
{
	return (mlx_destroy_image(graphics->mlx, picture));
}

