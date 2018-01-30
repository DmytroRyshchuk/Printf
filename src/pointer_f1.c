/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pointer_f1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:57:21 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 14:57:22 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			pointer_f_space(t_printf_s *s_p, char *st, int i, int k)
{
	if (s_p->flags[i] == ' ' && s_p->bp != 1 && st[0] != '-' &&
		s_p->w_f < ft_strlen(st))
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
			ft_putchar(' ');
			s_p->leng_p++;
			s_p->bp = 1;
		}
		k = 0;
	}
}

int				pointer_f_minus(t_printf_s *s_p, char *f, char *st, int i)
{
	if (s_p->flags[i] == '-')
	{
		fill_by_0x("0x", 0, s_p);
		if (s_p->p_f > ft_strlen(st) && s_p->bp == 0)
		{
			if (s_p->p_f > s_p->w_f)
				s_p->leng_p += fill_by_zero(s_p->p_f - ft_strlen(st));
			print_st(s_p, st);
			return (1);
		}
		if (s_p->w_f > ft_strlen(st))
		{
			s_p->leng_p += with_minus_sign(f, st, check_flags(f), 1);
			return (1);
		}
		print_st(s_p, st);
		return (1);
	}
	return (0);
}

int				pointer_f_plus(t_printf_s *s_p, char *st, int i)
{
	if (s_p->flags[i] == '+' && st[0] != '-' && s_p->bp != 9)
	{
		if (s_p->w_f > s_p->p_f && s_p->w_f > ft_strlen(st))
		{
			if (s_p->p_f != 0)
				s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f - 1);
			else
				s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen(st) - 1);
			if (s_p->p_f > ft_strlen(st))
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

static int		pointer_f_zero2(t_printf_s *s_p, char *st)
{
	if (s_p->w_f > ft_strlen(st))
	{
		fill_by_0x("0x", 2, s_p);
		s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f - 2);
		print_st(s_p, st);
		return (1);
	}
	return (0);
}

int				pointer_f_zero(t_printf_s *s_p, char *st)
{
	if (s_p->w_f > ft_strlen(st))
	{
		if (s_p->w_f > s_p->p_f && s_p->w_f > ft_strlen(st) &&
			s_p->p_f != 0 && s_p->bp != 25)
		{
			s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f);
			s_p->leng_p += fill_by_zero(s_p->p_f - ft_strlen(st));
			print_st(s_p, st);
			return (1);
		}
		fill_by_0x("0x", 0, s_p);
		s_p->leng_p += fill_by_zero(s_p->w_f - ft_strlen(st) - 2);
		(s_p->bp > 21) ? 0 : (s_p->bp = 21);
	}
	if (s_p->w_f > ft_strlen(st) && s_p->p_f == 0)
	{
		print_st(s_p, st);
		return (1);
	}
	if (pointer_f_zero2(s_p, st) == 1)
		return (1);
	return (0);
}
