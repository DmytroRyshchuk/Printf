/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_f3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:12:24 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:12:27 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		double_f3(t_printf_s *s_p, char *st, int k, char *f)
{
	while (s_p->flags[k])
		if (s_p->flags[k++] == '0')
		{
			if (precision(f) != 0)
			{
				s_p->leng_p += fill_by_empty(width(f) - precision(f) - 2);
				fill_by_sign(s_p, '+');
			}
			else
			{
				s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st) - 2);
				fill_by_sign(s_p, '+');
				if (width(f) - ft_strlen(st) >= 2)
					fill_by_sign(s_p, '0');
			}
			if (precision(f) > ft_strlen(st))
				fill_by_sign(s_p, '0');
			print_st(s_p, st);
			return (1);
		}
	return (0);
}

int		double_f9(t_printf_s *s_p, char *st, char *f, int k)
{
	while (s_p->flags[k])
		if (s_p->flags[k++] == '-')
		{
			k = 0;
			while (s_p->flags[k])
				if (s_p->flags[k++] == '+')
				{
					fill_by_sign(s_p, '+');
					k = -90;
					break ;
				}
			if (precision(f) > ft_strlen(st))
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
			print_st(s_p, st);
			if (width(f) > precision(f) && k == -90)
				s_p->leng_p += fill_by_empty(width(f) - precision(f) - 1);
			else if (width(f) > precision(f))
				s_p->leng_p += fill_by_empty(width(f) - precision(f));
			return (1);
		}
	return (0);
}

/*
**s_p put on 124 row
*/

int		double_f10(t_printf_s *s_p, char *st, char *f, int k)
{
	k = 0;
	while (s_p->flags[k])
		if (s_p->flags[k++] == '+')
		{
			if (st[0] == '-' && width(f) > ft_strlen(st))
			{
				s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
				print_st(s_p, st);
				return (1);
			}
			if (width(f) > precision(f) && precision(f) != 0)
				s_p->leng_p += fill_by_empty(width(f) - precision(f));
			fill_by_sign(s_p, '+');
			if (precision(f) > ft_strlen(st) - 1)
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st) - 1);
			print_st(s_p, st);
			return (1);
		}
	return (0);
}

int		double_f11(t_printf_s *s_p, char *st, char *f)
{
	if (width(f) > precision(f) && precision(f) != 0)
	{
		if (precision(f) > ft_strlen(st))
		{
			if (st[0] == '-')
				s_p->leng_p += fill_by_empty(width(f) - precision(f) - 1);
			else
				s_p->leng_p += fill_by_empty(width(f) - precision(f));
		}
		else
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
	}
	else if (width(f) > ft_strlen(st))
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
	if (precision(f) > ft_strlen(st))
	{
		if (st[0] == '-')
		{
			precision_bigger_str(f, st, s_p);
			return (1);
		}
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
	}
	return (0);
}

int		double_f12(t_printf_s *s_p, char *st, char *f, int k)
{
	if ((width(f) > precision(f) && width(f) > ft_strlen(st)) && s_p->bp < 20)
	{
		if (k != 12000)
		{
			if (double_f9(s_p, st, f, k) == 1)
				return (1);
			if (double_f11(s_p, st, f) == 1)
				return (1);
		}
	}
	else if (width(f) > ft_strlen(st) && s_p->bp < 20 && k == 0)
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
	else if (precision(f) > ft_strlen(st) && ft_strlen(st) > width(f))
	{
		if (st[0] == '-')
		{
			precision_bigger_str(f, st, s_p);
			return (1);
		}
		precision_bigger_str(f, st, s_p);
	}
	return (0);
}
