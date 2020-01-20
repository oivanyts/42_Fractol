/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:57:29 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/17 17:57:31 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "control.h"
#include "graphics.h"
#include "fractol.h"
#include "option_handler.h"

int	main(int argc, char *argv[])
{
	t_graphics	view[--argc];
	t_model		fractol[argc];
	int			window_count = 0;

	while (argc--)
	{
		window_count = option_handle(*(++argv), &fractol[window_count++]);
	}
	ft_printf("windows %d\n", window_count);
	init_graphics(&view, window_count, 800, 800);
	init_model(&fractol, &view, window_count);
	init_controls(&view, &fractol, window_count);
	run(&view[0]);
//	destroy_graphic(&view);
	return (0);
}
