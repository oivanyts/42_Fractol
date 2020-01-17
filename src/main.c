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
	int			&window_count;

	if (!option_handle(argc, ++argv, 0))
		return (EXIT_FAILURE);
	init_graphics(&view[argc], "Fractol", 800, 800);
	init_model(&fractol, &view.frame, view.w_window, view.h_window);
	run(&view, &fractol);
	destroy_graphic(&view);
	return (0);
}
