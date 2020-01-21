/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:29:15 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/15 17:29:17 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

bool	init_graphics(t_window new[], int count, char *names[])
{
	int		i;
	void	*tmp;

	tmp = mlx_init();
	i = 0;
	while (i < count)
	{
		if (!(new[i].mlx = tmp))
		{
			return (false);
		}
		if (!(new[i].win = mlx_new_window(new[i].mlx, WIDTH, HEIGHT,
				names[count - 1 - i])))
		{
			return (false);
		}
		new[i].w_window = WIDTH;
		new[i].h_window = HEIGHT;
		new[i].num = i;
		init_picture(&(new[i]));
		i++;
	}
	return (true);
}

bool	destroy_graphic(t_window *old)
{
	if (old && !destroy_picture(old))
	{
		return (mlx_destroy_window(old->mlx, old->win));
	}
	return (false);
}
