/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _octat_f2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:08:30 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:08:32 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		octat_f_zero(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = 0;
	if (precision(f) > ft_strlen(st))
	{
		while (s_p->flags[k])
			if (s_p->flags[k++] == '-')
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
	}
	else if (width(f) > ft_strlen(st))
	{
		s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	else if (precision(f) < ft_strlen(st))
	{
		while (s_p->flags[k])
			if (s_p->flags[k++] == '#')
			{
				s_p->leng_p++;
				fill_by_zero(1);
			}
	}
	return (0);
}

int		octat_f_plus(t_printf_s *s_p, char *f, char *st, int i)
{
	if ((s_p->flags[i] == '+' && s_p->flags[i + 1] != '0') ||
		(s_p->flags[i] == '#' && ft_strlen(s_p->flags) == 1))
	{
		if (s_p->flags[i] == '#' && width(f) == 0 && precision(f) != 0)
		{
			if (precision(f) > ft_strlen(st))
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
			print_st(s_p, st);
			return (1);
		}
		if (precision(f) > ft_strlen(st))
			s_p->leng_p += fill_by_empty(precision(f) - ft_strlen(st));
	}
	return (0);
}

int		octat_f_minus1(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = -1;
	while (s_p->flags[++k])
	{
		if (s_p->flags[k] == '#')
		{
			s_p->st = st;
			fill_by_sign(s_p, '0');
			print_st(s_p, st);
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(s_p->st) - 1);
			return (1);
		}
	}
	s_p->st = st;
	if (precision(f) > ft_strlen(st))
	{
		fill_by_sign(s_p, '0');
		print_st(s_p, st);
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(s_p->st) - 1);
		return (1);
	}
	print_st(s_p, st);
	s_p->leng_p += fill_by_empty(width(f) - ft_strlen(s_p->st));
	return (1);
}

int		octat_f_minus2(t_printf_s *s_p, char *f, char *st, int p)
{
	if (precision(f) > width(f) && precision(f) > ft_strlen(st))
	{
		s_p->leng_p = fill_by_zero(precision(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	if (width(f) > ft_strlen(st))
		if (octat_f_minus1(s_p, f, st) == 1)
			return (1);
	if (width(f) == 0)
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
	if (precision(f) > ft_strlen(st))
	{
		p = ft_strlen(st);
		(ft_strcmp(check_priority(f), " ")) ? ft_putchar('0') : 0;
		print_st(s_p, st);
		if (ft_strcmp(check_priority(f), " "))
			s_p->leng_p += fill_by_empty(precision(f) - p);
		else
			s_p->leng_p += fill_by_empty(precision(f));
		s_p->leng_p = s_p->leng_p;
		return (1);
	}
	return (0);
}

int		octat_f_sharp(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = 0;
	while (s_p->flags[k])
		if (s_p->flags[k++] == '-')
		{
			if (ft_strcmp(st, "0") != 0)
			{
				fill_by_sign(s_p, '0');
				print_st(s_p, st);
				s_p->leng_p += fill_by_empty(width(f) - ft_strlen(s_p->st) - 1);
				return (1);
			}
			print_st(s_p, st);
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(s_p->st));
			return (1);
		}
	if (ft_strcmp(st, "0") == 0)
	{
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
		fill_by_sign(s_p, '0');
		return (1);
	}
	s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st) - 1);
	return (0);
}
