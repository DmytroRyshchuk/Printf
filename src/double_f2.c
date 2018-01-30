/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_f2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:12:18 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:12:20 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		double_f4(t_printf_s *s_p, char *st, int k, char *f)
{
	if (width(f) > precision(f) && width(f) > ft_strlen(st))
	{
		if (double_f3(s_p, st, k, f) == 1)
			return (1);
		if (precision(f) != 0)
			s_p->leng_p += fill_by_empty(width(f) - precision(f) - 1);
		else
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st) - 1);
		fill_by_sign(s_p, '+');
		if (precision(f) > ft_strlen(st))
			fill_by_sign(s_p, '0');
		print_st(s_p, st);
		return (1);
	}
	s_p->bp = 9;
	fill_by_sign(s_p, '+');
	return (0);
}

int		double_f5(t_printf_s *s_p, char *st, int k, char *f)
{
	while (s_p->flags[k])
	{
		if (s_p->flags[k] == '+')
		{
			if (s_p->bp != 9 && st[0] != '-')
			{
				fill_by_sign(s_p, '+');
				s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st) - 1);
				print_st(s_p, st);
				return (1);
			}
		}
		k++;
	}
	if (st[0] == '-')
	{
		fill_by_sign(s_p, '-');
		s_p->bp = 25;
	}
	return (0);
}

int		double_f6(t_printf_s *s_p, char *st, char *f)
{
	if (width(f) > precision(f) && width(f) > ft_strlen(st) &&
		precision(f) != 0 && s_p->bp != 25)
	{
		if (precision(f) >= ft_strlen(st))
			s_p->leng_p += fill_by_empty(width(f) - precision(f));
		else
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	return (0);
}

int		double_f7(t_printf_s *s_p, char *st, char *f, int k)
{
	if (st[0] == '-')
		s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st));
	else
	{
		k = 0;
		while (s_p->flags[k])
			if (s_p->flags[k++] == ' ')
			{
				fill_by_sign(s_p, ' ');
				s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st) - 1);
				str_with_minus(st, s_p);
				return (1);
			}
		s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st));
	}
	str_with_minus(st, s_p);
	return (1);
}

int		double_f8(t_printf_s *s_p, char *st, char *f)
{
	if (check_dot(f) == 1 && value_zero(st) == 1)
	{
		if (width(f) > ft_strlen(st))
			s_p->leng_p += fill_by_empty(width(f));
		return (1);
	}
	if (((precision(f) > ft_strlen(st) && width(f) == 0) ||
		(precision(f) > width(f) && width(f) > ft_strlen(st))))
	{
		(*st == '-') ? s_p->leng_p++ : 0;
		(*st == '-') ? ft_putchar(*st++) : 0;
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	return (0);
}
