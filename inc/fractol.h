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
# include <math.h>
# include "complex.h"
# include "graphics.h"

typedef struct	s_model
{
	bool		alive;
	bool		updated;
	int			max_iter;
	void		(*fractal)(t_complex *c, t_complex *k, int max_iter, int *it);
	t_picture	*pic;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	k;
}				t_model;

void			init_model(t_model new[], t_window pic[], int size);
void			*tread_update(void *model);
void			set_position(t_model *model, int iterator, int x, int y);
void			mandelbrot(t_complex *c, t_complex *z, int max_iter, int *it);
void			julia(t_complex *c, t_complex *k, int max_iter, int *it);
void			third(t_complex *c, t_complex *k, int max_iter, int *it);

#endif
