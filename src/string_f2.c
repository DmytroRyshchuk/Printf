/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _string_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:01:40 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:01:42 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		string_f_zero(t_printf_s *s_p, char *st, char *f, int i)
{
	if (s_p->flags[i] == '0')
	{
		if (precision(f) > ft_strlen(st))
			s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		if (width(f) > ft_strlen(st))
		{
			s_p->leng_p += fill_by_zero(width(f) - ft_strlen(st));
			print_st(s_p, st);
			return (1);
		}
	}
	return (0);
}

void	string_f_plus(t_printf_s *s_p, char *st, char *f, int i)
{
	if ((s_p->flags[i] == '+' && s_p->flags[i + 1] != '0') ||
		(s_p->flags[i] == '#' && ft_strlen(s_p->flags) == 1))
		if (precision(f) > ft_strlen(st))
			s_p->leng_p += fill_by_empty(precision(f) - ft_strlen(st));
}

int		string_f_minus(t_printf_s *s_p, char *st, char *f, int i)
{
	if (s_p->flags[i] == '-')
	{
		if (precision(f) > ft_strlen(st))
		{
			i = ft_strlen(st);
			print_st(s_p, st);
			s_p->leng_p += fill_by_empty(precision(f) - i);
			return (1);
		}
		if (width(f) > 0)
		{
			print_st(s_p, st);
			if (width(f) > s_p->len && s_p->len < precision(f))
				s_p->leng_p += fill_by_empty(width(f) - s_p->len);
			else if (width(f) > ft_strlen(s_p->st) && precision(f) == 0)
				s_p->leng_p += S1;
			else if (width(f) > precision(f))
				s_p->leng_p += fill_by_empty(width(f) - precision(f));
			return (1);
		}
	}
	return (0);
}

int		string_flags(t_printf_s *s_p, char *st, char *f, int i)
{
	while (s_p->flags[i])
	{
		if (string_f_zero(s_p, st, f, i) == 1)
			return (1);
		string_f_plus(s_p, st, f, i);
		if (string_f_minus(s_p, st, f, i) == 1)
			return (1);
		i++;
	}
	if (i == 0 && precision(f) > 0)
		if (precision(f) > ft_strlen(st))
			s_p->leng_p += fill_by_empty(precision(f) - ft_strlen(st));
	print_st(s_p, st);
	return (1);
}

int		string_operations(t_printf_s *s_p, char *f, char *st, int i)
{
	i = 0;
	if (if_string_null(s_p, st, f, i) == 1)
		return (1);
	if (ft_strcmp(s_p->st, "0") == 0)
		st = s_p->st;
	s_p->len = ft_strlen(st);
	if (string_first_f(s_p, st, f) == 1)
		return (1);
	if (check_dot(f) == 1)
		if (string_check_dot(s_p, st, f, i) == 1)
			return (1);
	if (string_flags(s_p, st, f, i) == 1)
		return (1);
	return (0);
}
