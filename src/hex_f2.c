/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _hex_f2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:53:56 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 18:53:57 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		hex_f_zero(t_printf_s *s_p, char *f, char *st)
{
	if (width(f) > ft_strlen(st))
	{
		if (width(f) > s_p->p_f && width(f) > ft_strlen(st) && s_p->p_f != 0)
		{
			s_p->leng_p += fill_by_empty(width(f) - precision(f));
			s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
			print_st(s_p, st);
			return (1);
		}
		s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st));
		(s_p->bp > 21) ? 0 : (s_p->bp = 21);
	}
	if (width(f) > ft_strlen(st) && precision(f) == 0)
	{
		print_st(s_p, st);
		return (1);
	}
	if (width(f) > ft_strlen(st))
	{
		x_zero(s_p);
		s_p->leng_p += fill_by_empty(width(f) - precision(f) - 2);
		print_st(s_p, st);
		return (1);
	}
	return (0);
}

int		hex_f_sharp1(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = -1;
	while (s_p->flags[++k])
		if (s_p->flags[k] == '0')
		{
			if (width(f) > ft_strlen(st))
			{
				x_zero(s_p);
				s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st) - 2);
				print_st(s_p, st);
				return (1);
			}
		}
	return (0);
}

int		hex_f_sharp2(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = -1;
	while (s_p->flags[++k])
		if (s_p->flags[k] == '-')
		{
			if (width(f) > ft_strlen(st))
			{
				x_zero(s_p);
				s_p->st = st;
				print_st(s_p, st);
				s_p->leng_p += fill_by_empty(width(f) - ft_strlen(s_p->st) - 2);
				return (1);
			}
		}
	if (width(f) == 0 && precision(f) == 0 && (check_dot(f) == 1 ||
		ft_strcmp(st, "0") == 0) && s_p->flags == 0)
	{
		x_zero(s_p);
		print_st(s_p, st);
		return (1);
	}
	return (0);
}

int		hex_f_sharp3(t_printf_s *s_p, char *f, char *st)
{
	if (width(f) > ft_strlen(st))
	{
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st) - 2);
		x_zero(s_p);
		print_st(s_p, st);
		return (1);
	}
	else if (width(f) > precision(f) && precision(f) != 0)
		s_p->leng_p += fill_by_empty(width(f) - precision(f) - 2);
	if (precision(f) > ft_strlen(st))
	{
		x_zero(s_p);
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		print_st(s_p, st);
		return (1);
	}
	if (*st != '0')
		x_zero(s_p);
	print_st(s_p, st);
	return (1);
}

int		hex_flags(t_printf_s *s_p, char *f, char *st, int i)
{
	while (s_p->flags[i])
	{
		hex_f_empty(s_p, f, st, i);
		hex_f_minus(s_p, f, st, i);
		if (hex_f_plus(s_p, f, st, i) == 1)
			return (1);
		if (s_p->flags[i] == '0')
			if (hex_f_zero(s_p, f, st) == 1)
				return (1);
		if (s_p->flags[i] == '#')
		{
			if (hex_f_sharp1(s_p, f, st) == 1)
				return (1);
			if (hex_f_sharp2(s_p, f, st) == 1)
				return (1);
			if (hex_f_sharp3(s_p, f, st) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
