/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pointer_f3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:22:48 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:22:49 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_by_0x(char *what, int plus, t_printf_s *s_p)
{
	write(1, what, 2);
	s_p->leng_p += plus;
}

int		pointer_width(t_printf_s *s_p, char *f, char *st, int k)
{
	if ((s_p->w_f > s_p->p_f && s_p->w_f > ft_strlen(st)))
	{
		if (pointer_width1(s_p, st, k, 0) == 1)
			return (1);
		if (pointer_width2(s_p, st) == 1)
			return (1);
		else if (s_p->w_f > ft_strlen(st))
		{
			s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen(st) - 2);
			fill_by_0x("0x", 0, s_p);
			print_st(s_p, st);
			return (1);
		}
		else if (s_p->w_f > s_p->p_f && s_p->p_f != 0)
			s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f);
	}
	else if (s_p->w_f > ft_strlen(st) && s_p->bp < 20)
		s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen(st));
	else if (s_p->p_f > ft_strlen(st))
	{
		fill_by_0x("0x", 0, s_p);
		precision_bigger_str(f, st, s_p);
	}
	return (0);
}

int		pointer_make_it_short(t_printf_s *s_p, char *f, char *st, int i)
{
	if (check_dot(f) == 1 && value_zero(st) == 1)
	{
		fill_by_0x("0x", 0, s_p);
		if (s_p->w_f > ft_strlen(st))
			s_p->leng_p += fill_by_empty(s_p->w_f);
		else if (s_p->p_f > ft_strlen(st))
			s_p->leng_p += fill_by_zero(s_p->p_f);
		return (1);
	}
	if (pointer_flags(s_p, f, st, i) == 1)
		return (1);
	if (((s_p->p_f > ft_strlen(st) && s_p->w_f == 0) ||
		(s_p->p_f > s_p->w_f && s_p->w_f > ft_strlen(st))))
	{
		(*st == '-') ? s_p->leng_p++ : 0;
		(*st == '-') ? ft_putchar(*st++) : 0;
		s_p->leng_p += fill_by_zero(s_p->p_f - ft_strlen(st));
	}
	else if (pointer_width(s_p, f, st, 0) == 1)
		return (1);
	return (0);
}

int		pointer_operations(t_printf_s *s_p, char *f, char *st, int i)
{
	if (pointer_make_it_short(s_p, f, st, i) == 1)
		return (1);
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
	fill_by_0x("0x", 0, s_p);
	pointer_make_it_short2(s_p, f, st);
	return (1);
}

void	pointer_make_it_short2(t_printf_s *s_p, char *f, char *st)
{
	while (*st && (s_p->bp != 20))
	{
		if (s_p->bp == 25)
		{
			(*st != '-') ? s_p->leng_p++ : 0;
			(*st != '-') ? ft_putchar(*st++) : *st++;
		}
		else
		{
			if (dot_p(f) == 1)
				st++;
			else
			{
				ft_putchar(*st++);
				s_p->leng_p++;
			}
		}
	}
}
