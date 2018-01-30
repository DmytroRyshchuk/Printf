/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pointer_f2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:18:52 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:18:53 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pointer_f_sharp1(t_printf_s *s_p, char *st, int k)
{
	while (s_p->flags[++k])
		if (s_p->flags[k] == '0')
		{
			if (s_p->w_f > ft_strlen(st))
			{
				fill_by_0x("0x", 2, s_p);
				s_p->leng_p += fill_by_zero(s_p->w_f - ft_strlen(st) - 2);
				print_st(s_p, st);
				return (1);
			}
		}
	k = -1;
	while (s_p->flags[++k])
		if (s_p->flags[k] == '-')
		{
			if (s_p->w_f > ft_strlen(st))
			{
				fill_by_0x("0x", 2, s_p);
				s_p->st = st;
				print_st(s_p, st);
				s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen(s_p->st) - 2);
				return (1);
			}
		}
	return (0);
}

int		pointer_f_sharp(t_printf_s *s_p, char *f, char *st, int i)
{
	if (s_p->flags[i] == '#')
	{
		if (pointer_f_sharp1(s_p, st, -1) == 1)
			return (1);
		if (s_p->w_f == 0 && s_p->p_f == 0 && (check_dot(f) == 1 ||
			ft_strcmp(st, "0") == 0))
		{
			print_st(s_p, st);
			return (1);
		}
		if (s_p->w_f > ft_strlen(st))
			s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen(st) - 2);
		else if (s_p->w_f > s_p->p_f && s_p->p_f != 0)
			s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f - 2);
		if (s_p->p_f > ft_strlen(st))
			s_p->leng_p += fill_by_zero(s_p->p_f - ft_strlen(st) - 2);
		fill_by_0x("0x", 2, s_p);
		print_st(s_p, st);
		return (1);
	}
	return (0);
}

int		pointer_flags(t_printf_s *s_p, char *f, char *st, int i)
{
	while (s_p->flags[i])
	{
		pointer_f_space(s_p, st, i, 0);
		if (pointer_f_minus(s_p, f, st, i) == 1)
			return (1);
		if (pointer_f_plus(s_p, st, i) == 1)
			return (1);
		if (s_p->flags[i] == '0')
			if (pointer_f_zero(s_p, st) == 1)
				return (1);
		if (pointer_f_sharp(s_p, st, f, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

int		pointer_width1(t_printf_s *s_p, char *st, int k, int j)
{
	while (s_p->flags[k])
		if (s_p->flags[k++] == '-')
		{
			while (s_p->flags[j])
				if (s_p->flags[j++] == '+')
				{
					if (s_p->p_f > ft_strlen(st))
						s_p->leng_p += fill_by_zero(s_p->p_f - ft_strlen(st));
					print_st(s_p, st);
					if (s_p->w_f > s_p->p_f)
						s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f - 1);
					return (1);
				}
		}
	while (s_p->flags[k])
		if (s_p->flags[k++] == '+')
		{
			if (s_p->w_f > s_p->p_f && s_p->p_f != 0)
				s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f);
			if (s_p->p_f > ft_strlen(st) - 1)
				s_p->leng_p += fill_by_zero(s_p->p_f - ft_strlen(st) - 1);
			print_st(s_p, st);
			return (1);
		}
	return (0);
}

int		pointer_width2(t_printf_s *s_p, char *st)
{
	if (s_p->w_f > s_p->p_f && s_p->p_f != 0)
	{
		if (s_p->p_f > ft_strlen(st))
		{
			if (st[0] == '-')
				s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f - 1);
			else
			{
				s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen(st) - 2);
				s_p->leng_p += fill_by_zero(s_p->p_f - ft_strlen(st));
			}
		}
		else
		{
			s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen(st) - 2);
			fill_by_0x("0x", 0, s_p);
			print_st(s_p, st);
			return (1);
		}
	}
	return (0);
}
