/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_f1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:01:54 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/28 18:01:56 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		minus_and_plus_flags(char *s)
{
	int		i;
	int		m;
	int		p;

	i = 0;
	m = 0;
	p = 0;
	while (s[i])
	{
		if (s[i] == '-')
			m = 1;
		else if (s[i] == '+')
			p = 1;
		i++;
	}
	if (p + m == 2)
		return (1);
	return (0);
}

int		check_dot_full(char *s)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (((s[i - 1] >= 48 && s[i - 1] <= 57) &&
			(s[i + 1] >= 48 && s[i + 1] <= 57)) && s[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		double_f1(t_printf_s *s_p, char *f, char *st)
{
	if (minus_and_plus_flags(s_p->flags) == 1 && check_dot_full(f) == 0)
	{
		if (st[0] != '-')
			fill_by_sign(s_p, '+');
		print_st(s_p, st);
		if (s_p->st[0] != '-')
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(s_p->st) - 1);
		else
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(s_p->st));
		return (1);
	}
	return (0);
}

int		double_f2(t_printf_s *s_p, char *st, int i)
{
	int		k;

	k = 0;
	if (s_p->flags[i] == ' ' && s_p->bp != 1 && st[0] != '-' &&
		width(s_p->f) < ft_strlen(st))
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
			fill_by_sign(s_p, ' ');
			return (1);
		}
	}
	return (0);
}

int		double_f3_0(t_printf_s *s_p, char *st, int i, char *f)
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
