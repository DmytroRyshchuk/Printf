/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _wchar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:22:12 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/24 14:22:13 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wchar2(wchar_t c)
{
	if (c <= 65535)
	{
		ft_putchar((c >> 12) + 0b11100000);
		ft_putchar(((c >> 6) & 0b111111) + 0b10000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		return (3);
	}
	else if (c <= 1114111)
	{
		ft_putchar((c >> 18) + 0b11110000);
		ft_putchar(((c >> 12) & 0b111111) + 0b10000000);
		ft_putchar(((c >> 6) & 0b111111) + 0b10000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		return (4);
	}
	else
		return (0);
}

int			ft_wchar(wchar_t c)
{
	if (c > 255 && MB_CUR_MAX == 1)
		return (-1);
	else if (c <= 127 || (c <= 255 && MB_CUR_MAX == 1))
	{
		ft_putchar(c);
		return (1);
	}
	if (c <= 127)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c <= 2047)
	{
		ft_putchar((c >> 6) + 0b11000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		return (2);
	}
	else
		return (ft_wchar2(c));
}

int			ft_wchar_l(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else if (c <= 1114111)
		return (4);
	else
		return (0);
}
