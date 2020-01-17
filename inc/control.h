/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:11:39 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/16 15:11:44 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONTROL_H
# define FRACTOL_CONTROL_H

# include "graphics.h"
# include "fractol.h"

enum	e_keyboard
{
	PLUS = 69,
	MINUS = 78,
	ESC = 53
};

enum	e_mouse{
	LMK = 1,
	RMK = 2,
	SCR_UP = 4,
	SCR_DOWN = 5,
	SCR_LEFT = 6,
	SCR_RIGHT = 7
};

struct	s_general
{
	t_graphics	*view;
	t_model		*model;
};

int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		loop_hook(void *param);
void	run(t_graphics *new, t_model *model);

#endif
