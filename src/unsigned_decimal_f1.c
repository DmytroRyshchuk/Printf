/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unsigned_decimal_f1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:57:45 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/29 11:57:46 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		udec_f_minus(t_printf_s *s_p, char *f, char *st, int i)
{
	if (s_p->flags[i] == '-')
	{
		if (precision(f) > ft_strlen(st) && s_p->bp == 0)
		{
			if (precision(f) > width(f))
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
			return (1);
		}
		if (width(f) > ft_strlen(st))
		{
			s_p->leng_p += with_minus_sign(f, st, check_flags(f), 0);
			s_p->bp = 20;
		}
	}
	return (0);
}

int		udec_f_plus(t_printf_s *s_p, char *f, char *st, int i)
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
			{
				ft_putchar('0');
				s_p->leng_p++;
			}
			print_st(s_p, st);
			return (1);
		}
		s_p->bp = 9;
	}
	return (0);
}

void	udec_f_zero(t_printf_s *s_p, char *f, char *st, int i)
{
	if (s_p->flags[i] == '0')
	{
		if (width(f) > ft_strlen(st))
		{
			if (st[0] == '-')
			{
				ft_putchar('-');
				s_p->leng_p++;
				s_p->bp = 25;
			}
			s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st));
			(s_p->bp > 21) ? 0 : (s_p->bp = 21);
		}
	}
}
