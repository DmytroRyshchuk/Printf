/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_f4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:14:18 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:14:20 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	double_f_space_zero(t_printf_s *s_p, char *st, int i)
{
	if (s_p->flags[i] == ' ')
	{
		if (s_p->flags[i + 1] == '-')
			fill_by_sign(s_p, ' ');
		if (width(s_p->f) < precision(s_p->f) &&
			precision(s_p->f) > ft_strlen(st))
			fill_by_sign(s_p, ' ');
	}
	if (s_p->flags[i] == '0')
		if (width(s_p->f) < precision(s_p->f) &&
			precision(s_p->f) > ft_strlen(st))
			fill_by_sign(s_p, '0');
}

static void	double_f_minus(t_printf_s *s_p, char *st, int i, char *f)
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
			if (s_p->flags[i + 1] == ' ')
				fill_by_sign(s_p, ' ');
			s_p->leng_p += with_minus_sign(f, st, check_flags(f), 0);
			s_p->bp = 20;
		}
	}
	return (0);
}

int			double_flags(t_printf_s *s_p, char *st, int i, char *f)
{
	double_f_space_zero(s_p, st, i);
	if (double_f_minus(s_p, st, i, f) == 1)
		return (1);
	return (0);
}

int			double_f13(t_printf_s *s_p, char *st, int k, int i)
{
	while (s_p->flags[++i])
	{
		if (double_f1(s_p, s_p->f, st) == 1)
			return (1);
		if (double_f2(s_p, st, i) == 1)
			s_p->bp = 1;
		if (double_flags(s_p, st, i, s_p->f) == 1)
			return (0);
		if (s_p->flags[i] == '+' && st[0] != '-' && s_p->bp != 9)
			if (double_f4(s_p, st, k, s_p->f) == 1)
				return (1);
		if (s_p->flags[i] == '0')
		{
			if (width(s_p->f) > ft_strlen(st))
			{
				if (double_f5(s_p, st, k, s_p->f) == 1)
					return (1);
				if (double_f6(s_p, st, s_p->f) == 1)
					return (1);
				if (double_f7(s_p, st, s_p->f, k) == 1)
					return (1);
			}
		}
	}
	return (0);
}

void	double_f14(t_printf_s *s_p, char *st, int k, int i)
{
	if (double_f13(s_p, st, k, i) == 1)
		return ;
	if (double_f8(s_p, st, s_p->f) == 1)
		return ;
	else if (double_f12(s_p, st, s_p->f, k) == 1)
		return ;
	while (*st && (s_p->bp != 20))
	{
		if (s_p->bp == 25)
		{
			(*st != '-') ? s_p->leng_p++ : 0;
			(*st != '-') ? ft_putchar(*st++) : *st++;
		}
		else
		{
			ft_putchar(*st++);
			s_p->leng_p++;
		}
	}
	return ;
}
