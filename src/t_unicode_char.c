/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_unic_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:29:50 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/24 13:29:51 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		uni__char_1(t_printf_s *s_p, unsigned int ch, int i)
{
	if (s_p->flags[i] == '0')
	{
		s_p->leng_p += fill_by_zero(s_p->w_f - 1);
		s_p->leng_p += ft_wchar(ch);
		return (1);
	}
	if ((s_p->flags[i] == '+' && s_p->flags[i + 1] != '0') ||
		(s_p->flags[i] == '#' && ft_strlen(s_p->flags) == 1))
	{
		s_p->leng_p += fill_by_empty(s_p->w_f - 1);
		s_p->leng_p += ft_wchar(ch);
		return (1);
	}
	if (s_p->flags[i] == '-')
		if (s_p->p_f - 1)
		{
			s_p->leng_p += ft_wchar(ch);
			s_p->leng_p += fill_by_empty(s_p->w_f - ft_wchar_l(ch));
			return (1);
		}
	return (0);
}

int		unic_char(va_list ap, char *f, t_printf_s *s_p)
{
	int		ch;
	int		i;

	ch = va_arg(ap, int);
	s_p->leng_p = 0;
	s_p->p_f = precision(f);
	s_p->w_f = width(f);
	s_p->flags = check_flags(f);
	i = -1;
	while (s_p->flags[++i])
		if (uni__char_1(s_p, ch, i) == 1)
			return (1);
	if (s_p->w_f > 0)
		if (s_p->w_f > 1)
			s_p->leng_p += fill_by_empty(s_p->w_f - ft_wchar_l(ch));
	if (check_dot(f) == 1)
	{
		if (s_p->p_f > 0)
			s_p->leng_p += ft_wchar(ch);
		return (1);
	}
	if (i == 0 && s_p->p_f > 0)
		s_p->leng_p += fill_by_empty(s_p->p_f - 1);
	s_p->leng_p += ft_wchar(ch);
	return (1);
}
