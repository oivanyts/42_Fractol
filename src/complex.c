/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:45:14 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/17 17:45:17 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

void	init_complex(t_complex *com_ptr, double real, double imaginable)
{
	com_ptr->re = real;
	com_ptr->im = imaginable;
}

void	interpolation(t_complex *src, t_complex *mouse, double interp)
{
	src->im = mouse->im + (src->im - mouse->im) * interp;
	src->re = mouse->re + (src->re - mouse->re) * interp;
}
