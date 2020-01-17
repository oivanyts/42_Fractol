/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:12:13 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/16 15:12:17 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include <stdbool.h>
# include  <math.h>
# include "complex.h"
# include "graphics.h"

typedef struct	s_model
{
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	int			max_iter;
	bool		updated;
	t_picture	*pic;
	void		(*formula)(double re, double im, int max_iter, int *it);
}				t_model;

void			init_model(t_model *new, t_picture *pic, int width, int height);
void			update_model(t_model *model);
void			*tread_update(void *model);
void			set_position(t_model *model, int iterator, int x, int y);
void			mandelbrot(double re, double im, int max_iter, int *it);

#endif
