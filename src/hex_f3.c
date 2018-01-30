/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _hex_f3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:55:17 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 18:55:20 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		hex_width1(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = 0;
	while (s_p->flags[k])
		if (s_p->flags[k++] == '-')
		{
			k = 0;
			while (s_p->flags[k])
				if (s_p->flags[k++] == '+')
				{
					k = -90;
					break ;
				}
			if (precision(f) > ft_strlen(st))
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
			print_st(s_p, st);
			if (width(f) > precision(f) && k == -90)
				s_p->leng_p += fill_by_empty(width(f) - precision(f) - 1);
			else if (width(f) > precision(f))
				s_p->leng_p += fill_by_empty(width(f) - precision(f));
			return (1);
		}
	return (0);
}

int		hex_width2(t_printf_s *s_p, char *f, char *st)
{
	int		k;

	k = 0;
	while (s_p->flags[k])
		if (s_p->flags[k++] == '+')
		{
			if (width(f) > precision(f) && precision(f) != 0)
				s_p->leng_p += fill_by_empty(width(f) - precision(f));
			if (precision(f) > ft_strlen(st) - 1)
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st) - 1);
			print_st(s_p, st);
			return (1);
		}
	return (0);
}

void	hex_width3(t_printf_s *s_p, char *f, char *st)
{
	if (width(f) > precision(f) && precision(f) != 0)
	{
		if (precision(f) > ft_strlen(st))
		{
			if (st[0] == '-')
				s_p->leng_p += fill_by_empty(width(f) - precision(f) - 1);
			else
			{
				s_p->leng_p += fill_by_empty(width(f) - precision(f));
				s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
			}
		}
		else
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
	}
	else if (width(f) > ft_strlen(st))
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
	else if (width(f) > precision(f) && precision(f) != 0)
		s_p->leng_p += fill_by_empty(width(f) - precision(f));
}

int		hex_make_it_short(t_printf_s *s_p, char *f, char *st)
{
	if (((precision(f) > ft_strlen(st) && width(f) == 0) ||
		(precision(f) > width(f) && width(f) > ft_strlen(st))) &&
		(s_p->bp < 20))
	{
		(*st == '-') ? s_p->leng_p++ : 0;
		(*st == '-') ? ft_putchar(*st++) : 0;
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
	}
	else if ((width(f) > s_p->p_f && width(f) > ft_strlen(st)) && s_p->bp < 20)
	{
		if (hex_width1(s_p, f, st) == 1)
			return (1);
		if (hex_width2(s_p, f, st) == 1)
			return (1);
		hex_width3(s_p, f, st);
	}
	else if (width(f) > ft_strlen(st) && s_p->bp < 20)
		s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
	else if (precision(f) > ft_strlen(st))
		precision_bigger_str(f, st, s_p);
	return (0);
}

int		hex_operations(t_printf_s *s_p, char *f, char *st, int i)
{
	if (check_dot(f) == 1 && value_zero(st) == 1)
	{
		if (width(f) > ft_strlen(st))
			s_p->leng_p += fill_by_empty(width(f));
		return (1);
	}
	if (hex_flags(s_p, f, st, i) == 1)
		return (1);
	if (hex_make_it_short(s_p, f, st) == 1)
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
			ft_putchar(*st);
			st++;
			s_p->leng_p++;
		}
	}
	return (1);
}
