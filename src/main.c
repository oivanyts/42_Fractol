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

void	loop(void *mlx)
{
	mlx_loop(mlx);
}

int		main(int argc, char *argv[])
{
	t_window	view[--argc];
	t_model		models[argc];
	t_general	general;

	general = (t_general){ &view, &models, 0};
	while (argc--)
	{
		if (!(general.size =
				option_handle(argv[argc + 1], &models[general.size++])))
			return (usage_print());
	}
	if (!general.size)
		return (usage_print());
	if (!init_graphics(view, general.size, ++argv))
		return (1);
	init_model(models, view, general.size);
	init_controls(&general);
	loop(view[0].mlx);
	return (0);
}
