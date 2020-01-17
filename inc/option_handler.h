/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:42:30 by oivanyts          #+#    #+#             */
/*   Updated: 2020/01/17 17:42:34 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_OPTION_HANDLER_H
# define FRACTOL_OPTION_HANDLER_H

# include "libft.h"

void usage_print();

bool option_handle(int num, char *argv[], int window_count);
#endif
