/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 01:00:50 by oivanyts          #+#    #+#             */
/*   Updated: 2019/04/12 01:00:54 by oivanyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static inline bool	ft_ishex(char c)
{
	return (ft_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

static inline bool	ft_isoctal(char c)
{
	return (c >= '0' && c <= '8');
}

unsigned int		ft_atoi_hex(const char *str)
{
	unsigned long long	x;

	x = 0;
	while (ft_isspace(*str))
		str++;
	if (!(*str++ == '0' && *str++ == 'x'))
	{
		return (0);
	}
	while (*str && ft_ishex(*str))
	{
		x = x << 4;
		if (*str > 64)
			x += ft_toupper(*str) - 55;
		else
			x += (*str - 48);
		str++;
	}
	return (x);
}

unsigned int		ft_atoi_oct(const char *str)
{
	unsigned long long	x;

	x = 0;
	while (ft_isspace(*str))
		str++;
	if (*str++ != '0')
	{
		return (0);
	}
	while (*str && ft_isoctal(*str))
	{
		x = (x << 3) + (*str - 48);
	}
	return (x);
}

unsigned int		ft_atoi_base(const char *str)
{
	if (*str == '0')
	{
		if ((*str + 1) != 'x')
			return (ft_atoi_hex(str));
		else
			return (ft_atoi_oct(str));
	}
	else
	{
		return (ft_atoi(str));
	}
}
