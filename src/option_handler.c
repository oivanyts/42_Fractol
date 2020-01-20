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

const char *a[] = {
		"Mandelbrot",
		"Julia",
		"Third"
};

void		(*fractal[3])(double re, double im, int max_iter, int *it) = {
		&mandelbrot,
		&julia,
		&third
};

/*
void usage_print()
{
	ft_printf("Usage: fractol [-aDde] [-f | -g] "
	"[-n number] [-b b_arg | -c c_arg] req1 req2 [opt1 [opt2]]");
}
*/

int option_handle(char *option, t_model *curr_fractol)
{
	static int count;
	int i;

	i = sizeof(a)/ sizeof(*a);
	while (i--)
	{
		if (!ft_strcmp(option, a[i]))
		{
			curr_fractol->fractal = fractal[i];
			return(++count);
		}
	}
	return (false);
}
