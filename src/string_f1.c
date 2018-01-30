/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _string_f1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:35:29 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 11:35:30 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		if_string_null(t_printf_s *s_p, char *st, char *f, int i)
{
	if (st == NULL)
	{
		if ((ft_strcmp(s_p->flags, " ") == 0 || ft_strcmp(s_p->flags, "") == 0
			|| st == NULL) && check_dot(f) == 0)
		{
			st = "(null)";
			if (precision(f) >= 6 || precision(f) == 0)
			{
				s_p->leng_p += 6;
				write(1, st, 6);
			}
			else if (precision(f) < 6)
				while (*st && i++ < precision(f))
				{
					s_p->leng_p++;
					ft_putchar(*st++);
				}
			return (1);
		}
		else
			s_p->st = "0";
	}
	return (0);
}

int		string_first_f(t_printf_s *s_p, char *st, char *f)
{
	if (width(f) > 0 && ft_strcmp(s_p->flags, "") == 0 && (check_dot(f) != 1
		|| ft_strlen(st) > 0))
	{
		if (width(f) > ft_strlen(st) && ft_strlen(st) < precision(f))
		{
			s_p->leng_p += fill_by_empty(width(f) - ft_strlen(st));
			print_st(s_p, st);
			return (1);
		}
		else if (width(f) > ft_strlen(st) && precision(f) == 0)
			s_p->leng_p += fill_by_empty(width(f) - s_p->p_f - ft_strlen(st));
		else if (width(f) > precision(f))
			s_p->leng_p += fill_by_empty(width(f) - precision(f));
	}
	return (0);
}

int		string_check_dot(t_printf_s *s_p, char *st, char *f, int i)
{
	if (precision(f) < ft_strlen(st))
		while (*st && i++ < precision(f))
		{
			s_p->leng_p++;
			ft_putchar(*st++);
		}
	else
		print_st(s_p, st);
	if (width(f) > 0)
	{
		i = 0;
		while (s_p->flags[i])
			if (s_p->flags[i++] == '0')
			{
				s_p->leng_p += fill_by_zero(width(f));
				return (1);
			}
		if (width(f) > s_p->len && s_p->len < precision(f))
			s_p->leng_p += fill_by_empty(width(f) - s_p->len);
		else if (width(f) > ft_strlen(s_p->st) && precision(f) == 0)
			s_p->leng_p += S1;
		else if (width(f) > precision(f) && s_p->flags[0] == '-')
			s_p->leng_p += fill_by_empty(width(f) - precision(f));
	}
	return (1);
}
