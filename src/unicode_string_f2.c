/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unicode_string_f2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:04:38 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/30 19:04:40 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	uni_str4(t_printf_s *s_p, int v)
{
	if (s_p->w_f > ft_strlen_wchar(s_p->st_wc) &&
		ft_strlen_wchar(s_p->st_wc) < s_p->p_f)
		s_p->leng_p += fill_by_empty(s_p->w_f - ft_strlen_wchar(s_p->st_wc));
	else if (s_p->w_f > ft_strlen_wchar(s_p->st_wc)
		&& s_p->p_f == 0 && v == 0)
		s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f -
			ft_strlen_wchar(s_p->st_wc));
	else if (s_p->w_f > ft_strlen_wchar(s_p->st_wc)
		&& s_p->p_f == 0 && v == 1)
		s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f - s_p->leng_p);
	else if (s_p->w_f > s_p->p_f && s_p->flags[0] == '-' && v == 0)
		s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f);
	else if (s_p->w_f > s_p->p_f && v == 1)
		s_p->leng_p += fill_by_empty(s_p->w_f - s_p->p_f);
}

int		uni_str5(t_printf_s *s_p, wchar_t *st, int i, char *f)
{
	if (check_dot(f) == 1)
	{
		if (uni_str3(s_p, st, 0) == 1)
			return (1);
		if (s_p->w_f > 0)
		{
			while (s_p->flags[++i])
				if (s_p->flags[i] == '0')
				{
					s_p->leng_p += fill_by_zero(s_p->w_f);
					return (1);
				}
			uni_str4(s_p, 0);
			return (1);
		}
	}
	return (0);
}

int		uni_str6_1(t_printf_s *s_p, wchar_t *st, int i)
{
	int		p;

	p = 0;
	if (s_p->flags[i] == '-')
	{
		if (s_p->p_f > ft_strlen_wchar(st))
		{
			p = ft_strlen_wchar(st);
			uni_str0(s_p, st);
			s_p->leng_p += fill_by_empty(s_p->p_f - p);
			return (1);
		}
		if (s_p->w_f > 0)
		{
			uni_str0(s_p, st);
			uni_str4(s_p, 1);
			return (1);
		}
	}
	return (0);
}

int		uni_str6(t_printf_s *s_p, wchar_t *st, int i)
{
	if (s_p->flags[i] == '0')
	{
		if (s_p->p_f > ft_strlen_wchar(st))
			s_p->leng_p += fill_by_zero(s_p->p_f - ft_strlen_wchar(st));
		if (s_p->w_f > ft_strlen_wchar(st))
		{
			s_p->leng_p += fill_by_zero(s_p->w_f - calc_uni_str(st));
			uni_str0(s_p, st);
			return (1);
		}
	}
	if ((s_p->flags[i] == '+' && s_p->flags[i + 1] != '0') ||
		(s_p->flags[i] == '#' && ft_strlen(s_p->flags) == 1))
		if (s_p->p_f > ft_strlen_wchar(st))
			s_p->leng_p += fill_by_empty(s_p->p_f - ft_strlen_wchar(st));
	if (uni_str6_1(s_p, st, i) == 1)
		return (1);
	return (0);
}
