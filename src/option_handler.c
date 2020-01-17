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

/*
void usage_print()
{
	ft_printf("Usage: fractol [-aDde] [-f | -g] "
	"[-n number] [-b b_arg | -c c_arg] req1 req2 [opt1 [opt2]]");
}
*/

bool option_handle(int num, char *argv[], int window_count)
{
	int i;

	i = sizeof(a)/ sizeof(*a);
	if (num != 1)
		return (false);
	window_count = 0;
	while (window_count < num)
	{
		while (i--)
		{
			if (!ft_strcmp(argv[window_count], a[i]))

				return(true);
		}
		window_count++;
	}
	return (false);
}
