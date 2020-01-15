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

bool	init(t_graphics *not_initialized)
{
	return (not_initialized->mlx = mlx_init());
}

bool	initWindow(t_graphics *not_initialized)
{
	return (not_initialized->win = mlx_new_window(not_initialized->mlx, WIDTH, HEIGHT, "Fractol"));
}