/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:11:18 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/16 15:11:23 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_COMPLEX_H
#define FRACTOL_COMPLEX_H

typedef struct	s_complex{
	double		re;
	double		im;
}				t_complex;


void			init_complex(t_complex *com_ptr, double real, double imaginable);
#endif
