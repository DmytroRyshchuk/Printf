/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _t_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:12:25 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/10 12:12:27 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	char_0(char ch, t_printf_s *s_p)
{
	ft_putchar(ch);
	s_p->leng_p++;
}

int		char_1(int i, char ch, t_printf_s *s_p)
{
	if (s_p->flags[i] == '0')
	{
		s_p->leng_p += fill_by_zero(s_p->w_f - 1);
		char_0(ch, s_p);
		return (1);
	}
	if ((s_p->flags[i] == '+' && s_p->flags[i + 1] != '0') ||
		(s_p->flags[i] == '#' && ft_strlen(s_p->flags) == 1))
	{
		s_p->leng_p += fill_by_empty(s_p->w_f - 1);
		char_0(ch, s_p);
		return (1);
	}
	return (0);
}

int		char_1_1(int i, char ch, t_printf_s *s_p)
{
	if (s_p->flags[i] == '-')
		if (s_p->p_f - 1)
		{
			char_0(ch, s_p);
			s_p->leng_p += fill_by_empty(s_p->p_f - 1);
			return (1);
		}
	return (0);
}

int		char_2(t_printf_s *s_p, int minus, char ch, int i)
{
	if (s_p->w_f > 0)
		if (s_p->w_f > 1)
			s_p->leng_p += fill_by_empty(s_p->w_f - 1);
	if (check_dot(s_p->f) == 1)
	{
		if (s_p->p_f > 0)
			char_0(ch, s_p);
		return (1);
	}
	if (i == 0 && s_p->p_f > 0)
		s_p->leng_p += fill_by_empty(s_p->p_f - 1);
	if (minus == 0)
		char_0(ch, s_p);
	return (0);
}

void	char_result(va_list ap, t_printf_s *s_p)
{
	char			ch;
	int				i;
	int				minus;

	i = -1;
	s_p->pr_t = check_priority(s_p->f);
	s_p->w_f = width(s_p->f);
	if (C1)
		return ;
	ch = (char)va_arg(ap, void*);
	s_p->leng_p = 0;
	minus = 0;
	if (ft_strcmp(s_p->pr_t, "l") == 0)
	{
		s_p->leng_p += ft_printf("%C", ch);
		return ;
	}
	while (s_p->flags[++i])
		if (char_1(i, ch, s_p) == 1)
			return ;
		else if (char_1_1(i, ch, s_p) == 1)
			minus = 1;
	if (char_2(s_p, minus, ch, i) == 1)
		return ;
}
