/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:30:27 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/17 18:30:28 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option_handler.h"

int		usage_print(void)
{
	ft_printf("Usage: fractol julia mandelbrot ship\n");
	return (1);
}

int		option_handle(char *option, t_model *curr_fractol)
{
	static int	count;
	int			i;
	char		*names[3];
	void		(*fractals[3])(t_complex *, t_complex *, int, int *);

	names[0] = "mandelbrot";
	names[1] = "julia";
	names[2] = "ship";
	fractals[0] = &mandelbrot;
	fractals[1] = &julia;
	fractals[2] = &third;
	i = sizeof(names) / sizeof(*names);
	while (i--)
	{
		if (!ft_strcmp(option, names[i]))
		{
			curr_fractol->fractal = fractals[i];
			return (++count);
		}
	}
	return (false);
}
