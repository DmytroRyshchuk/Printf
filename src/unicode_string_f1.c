/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unicode_string_f1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:03:50 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:03:51 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		calc_uni_str(wchar_t *st)
{
	int		d;

	d = 0;
	while (*st)
		d += ft_wchar_l(*st++);
	return (d);
}

void	uni_str0(t_printf_s *s_p, wchar_t *st)
{
	while (*st)
	{
		s_p->leng_p += ft_wchar_l(*st);
		ft_wchar(*st++);
	}
}

void	uni_str1(t_printf_s *s_p, wchar_t *st)
{
	s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen_wchar(st));
	uni_str0(s_p, st);
	return ;
}

int		uni_str2(t_printf_s *s_p, wchar_t *st, char *f)
{
	if (s_p->w_f > 0 && ft_strcmp(s_p->flags, "") == 0 &&
	(check_dot(f) != 1 || ft_strlen_wchar(st) > 0))
	{
		if (US1 || US2)
		{
			uni_str1(s_p, st);
			return (1);
		}
		else if (s_p->w_f > s_p->p_f)
		{
			if (s_p->p_f > 3)
				s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f + 1);
			else
				s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f);
		}
	}
	return (0);
}

int		uni_str3(t_printf_s *s_p, wchar_t *st, int ar)
{
	ar = 0;
	while (*st && ar < s_p->p_f)
	{
		if (ar + ft_wchar_l(*st) > s_p->p_f)
			return (1);
		ar += ft_wchar_l(*st);
		s_p->leng_p += ft_wchar_l(*st);
		ft_wchar(*st++);
	}
	return (0);
}
