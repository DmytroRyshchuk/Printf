/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _hex_f1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:39:26 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/29 10:39:28 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	x_zero(t_printf_s *s_p)
{
	ft_putchar('0');
	ft_putchar(s_p->h);
	s_p->leng_p += 2;
}

void	hex_f_empty(t_printf_s *s_p, char *f, char *st, int i)
{
	int		k;

	k = 0;
	if (s_p->flags[i] == ' ' && s_p->bp != 1 && st[0] != '-' &&
		width(f) < ft_strlen(st))
	{
		while (s_p->flags[k])
		{
			if (s_p->flags[k] == '+')
			{
				k = 12000;
				break ;
			}
			k++;
		}
		if (k != 12000)
		{
			ft_putchar(' ');
			s_p->leng_p++;
			s_p->bp = 1;
		}
	}
}

void	hex_f_minus(t_printf_s *s_p, char *f, char *st, int i)
{
	if (s_p->flags[i] == '-')
	{
		if (precision(f) > ft_strlen(st) && s_p->bp == 0)
			if (precision(f) > width(f))
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		if (width(f) > ft_strlen(st))
		{
			s_p->leng_p += with_minus_sign(f, st, check_flags(f), 0);
			s_p->bp = 20;
		}
	}
}

int		hex_f_plus(t_printf_s *s_p, char *f, char *st, int i)
{
	if (s_p->flags[i] == '+' && st[0] != '-' && s_p->bp != 9)
	{
		if (width(f) > precision(f) && width(f) > ft_strlen(st))
		{
			if (precision(f) != 0)
				s_p->leng_p += fill_by_empty(width(f) - precision(f) - 1);
			else
				s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st) - 1);
			if (precision(f) > ft_strlen(st))
				fill_by_sign(s_p, '0');
			print_st(s_p, st);
			return (1);
		}
		s_p->bp = 9;
	}
	return (0);
}
