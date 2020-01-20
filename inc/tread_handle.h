/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread_handle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:44:03 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/17 17:44:06 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_TREAD_HANDLE_H
# define FRACTOL_TREAD_HANDLE_H

# include <pthread.h>
# include "fractol.h"

# define MAX_THREADS 40

typedef struct		s_threads
{
	pthread_t		worker;
	int				i;
	t_model			*model;
}					t_threads;

void				add_tread(t_model *model, t_threads *fresh);
bool				join_thread(t_threads *old);
void				handle_threads(t_model *model);

#endif
