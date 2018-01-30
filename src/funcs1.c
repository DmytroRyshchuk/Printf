/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:45:45 by dryshchu          #+#    #+#             */
/*   Updated: 2018/01/22 12:45:46 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	precision_bigger_str(char *f, char *st, t_printf_s *s_p)
{
	if (st[0] == '-')
	{
		st++;
		ft_putchar('-');
		s_p->leng_p++;
		s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
		while (*st)
		{
			ft_putchar(*st++);
			s_p->leng_p++;
		}
		return ;
	}
	s_p->leng_p += fill_by_zero(precision(f) - ft_strlen(st));
}

void	str_with_minus(char *st, t_printf_s *s_p)
{
	while (*st)
	{
		if (*st == '-')
			st++;
		ft_putchar(*st++);
		s_p->leng_p++;
	}
}

void	fill_by_sign(t_printf_s *s_p, char sign)
{
	ft_putchar(sign);
	s_p->leng_p++;
}

void	print_st(t_printf_s *s_p, char *st)
{
	while (*st)
	{
		ft_putchar(*st++);
		s_p->leng_p++;
	}
}
