/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _octat_f1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:07:27 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/29 17:07:28 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		octat_first_f(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = 0;
	if (check_dot(f) == 1 && value_zero(st) == 1)
	{
		while (f[k])
		{
			if (f[k] == '#')
				while (*st)
				{
					s_p->leng_p++;
					ft_putchar(*st++);
				}
			k++;
		}
		if (width(f) > ft_strlen(st))
			s_p->leng_p += fill_by_empty(width(f));
		return (1);
	}
	return (0);
}

int		octat_flags(t_printf_s *s_p, char *f, int i)
{
	while (s_p->flags[i])
	{
		if (s_p->flags[i] == '0')
			if (octat_f_zero(s_p, f, s_p->st) == 1)
				return (1);
		if (octat_f_plus(s_p, f, s_p->st, i) == 1)
			return (1);
		if (s_p->flags[i] == '-')
			if (octat_f_minus2(s_p, f, s_p->st, 0) == 1)
				return (1);
		if (s_p->flags[i] == '#')
		{
			if (octat_f_sharp(s_p, f, s_p->st) == 1)
				return (1);
			fill_by_sign(s_p, '0');
			print_st(s_p, s_p->st);
			return (1);
		}
		i++;
	}
	return (0);
}

int		octat_f1(t_printf_s *s_p, char *f, char *st)
{
	if (width(f) < ft_strlen(st) && precision(f) < ft_strlen(st))
	{
		print_st(s_p, st);
		return (1);
	}
	if (precision(f) > ft_strlen(st) && width(f) == 0)
	{
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	if (width(f) > ft_strlen(st) && precision(f) < ft_strlen(st))
	{
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	if (width(f) > 0 && width(f) < precision(f))
	{
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	return (0);
}

int		octat_f2(t_printf_s *s_p, char *f, char *st)
{
	if (width(f) > 0 && width(f) > precision(f))
	{
		s_p->leng_p += fill_by_empty(width(f) - precision(f));
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	if (width(f) > 0)
		if (width(f) > ft_strlen(st))
		{
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
			print_st(s_p, st);
			return (1);
		}
	if (check_dot(f) == 1)
	{
		if (precision(f) > 0)
			print_st(s_p, st);
		return (1);
	}
	return (0);
}

int		octat_operations(t_printf_s *s_p, char *f, int i, size_t original)
{
	if (octat_first_f(s_p, f, s_p->st) == 1)
		return (1);
	if (octat_flags(s_p, f, i) == 1)
		return (1);
	if (octat_f1(s_p, f, s_p->st) == 1)
		return (1);
	if (octat_f2(s_p, f, s_p->st) == 1)
		return (1);
	if (i == 0 && precision(f) > 0)
		if (precision(f) > ft_strlen(s_p->st) - 1)
		{
			if (ft_strcmp(check_priority(f), "h") && (int)original < 0)
			{
				s_p->leng_p += fill_by_empty(s_p->p_f - ft_strlen(s_p->st) - 1);
				fill_by_sign(s_p, '1');
			}
			else if (ft_strcmp(check_priority(f), " "))
				s_p->leng_p += fill_by_empty(s_p->p_f - ft_strlen(s_p->st) - 1);
			else
				s_p->leng_p += fill_by_empty(precision(f) - ft_strlen(s_p->st));
		}
	print_st(s_p, s_p->st);
	return (0);
}
