/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unsigned_decimal_f2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:25:24 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:25:27 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		udec_width1(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = 0;
	if ((width(f) > precision(f) && width(f) > ft_strlen(st)) && s_p->bp < 20)
	{
		while (s_p->flags[k])
			if (s_p->flags[k++] == '-')
			{
				if (precision(f) > ft_strlen(st))
					s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
				print_st(s_p, st);
				return (1);
			}
		if (width(f) > s_p->p_f && s_p->p_f != 0 && s_p->p_f < ft_strlen(st))
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
		else if (width(f) > precision(f) && precision(f) != 0)
			s_p->leng_p += fill_by_empty(width(f) - precision(f));
		else if (width(f) > ft_strlen(st))
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
		if (precision(f) > ft_strlen(st))
			s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
	}
	else if (udec_width2(s_p, f, st) == 1)
		return (1);
	return (0);
}

int		udec_width2(t_printf_s *s_p, char *f, char *st)
{
	if (width(f) > ft_strlen(st) && s_p->bp < 20)
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
	else if (precision(f) > ft_strlen(st) && ft_strlen(st) > width(f))
	{
		if (st[0] == '-')
		{
			st++;
			ft_putchar('-');
			s_p->leng_p++;
			s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
			print_st(s_p, st);
			return (1);
		}
		else
			s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
	}
	return (0);
}

int		udec_make_it_short(t_printf_s *s_p, char *f, char *st)
{
	if (((precision(f) > ft_strlen(st) && width(f) == 0) ||
		(precision(f) > width(f) && width(f) > ft_strlen(st))) &&
		(s_p->bp < 20))
	{
		(*st == '-') ? s_p->leng_p++ : 0;
		(*st == '-') ? ft_putchar(*st++) : 0;
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
	}
	else if (udec_width1(s_p, f, st) == 1)
		return (1);
	return (0);
}

int		udec_check_dot(t_printf_s *s_p, char *f, char *st)
{
	if (check_dot(f) == 1)
	{
		while (*st)
		{
			if (ft_strcmp(st, "0") == 0)
				st++;
			else
			{
				ft_putchar(*st++);
				s_p->leng_p++;
			}
		}
		return (1);
	}
	return (0);
}

int		udec_operations(t_printf_s *s_p, char *f, char *st, int i)
{
	while (s_p->flags[++i])
	{
		if (udec_f_minus(s_p, f, st, i) == 1)
			break ;
		if (udec_f_plus(s_p, f, st, i) == 1)
			return (1);
		udec_f_zero(s_p, f, st, i);
	}
	udec_make_it_short(s_p, f, st);
	if (udec_check_dot(s_p, f, st) == 1)
		return (1);
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
	return (1);
}
